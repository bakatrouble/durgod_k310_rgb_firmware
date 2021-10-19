//
// Created by bakatrouble on 19/10/2021.
//

#include <iap.h>
#include "modules/KeyboardMain.h"
#include "layout.h"

void KeyboardMain::init() {
    // init hardware
    rows.mode(PullUp);
    cols = 1;
    ledController.init();

    // start USB HID
    keyboardHid.setKeyboardMain(this);
    keyboardHid.init();

    // enable backlight
    ledController.setAllKeys(settings.ledColor);
    ledController.toggleFrame();
}

void KeyboardMain::loop() {
    scanKeys();
    processEvents();
    wait(.005);
//    led_app = !led_app;
}

void KeyboardMain::scanKeys() {
    uint8_t row, col;
    for (col=0; col < 16; col++) {
        cols = ~(1 << col);
        for (row=0; row < 8; row++) {
            uint8_t idx = matrixToIndex[row][col];
            uint16_t keycode = indexToKeycode[state == NORMAL ? 0 : 1][idx];
            if ((rows & (1 << row)) == 0) {
                if (pressedKeycodes.count(keycode) == 0) {
                    eventsQueue.push_back({EventType::KEY_PRESSED, keycode});
                }
            } else {
                if (pressedKeycodes.count(keycode) > 0) {
                    eventsQueue.push_back({EventType::KEY_RELEASED, keycode});
                }
            }
        }
        cols = 1;
    }
}

void KeyboardMain::processEvents() {
    bool keysChanged = false;
    while (!eventsQueue.empty()) {
        KeyboardEvent event = eventsQueue.front();
        switch (event.event) {
            case KEY_PRESSED:
//                pressedKeys[event.arg] = true;
                pressedKeycodes.insert(event.arg);
                keysChanged = true;
                break;
            case KEY_RELEASED:
//                pressedKeys[event.arg] = false;
                pressedKeycodes.erase(event.arg);
                keysChanged = true;
                break;
            case VENDOR_COMMAND_RECEIVED:
                processVendorCommand();
                break;
            case LEDS_RECEIVED:
                led_num = !(event.arg & 0x1);
                led_caps = !(event.arg & 0x2);
                led_scroll = !(event.arg & 0x4);
                break;
        }
        eventsQueue.pop_front();
    }
    if (keysChanged) {
        processPressedKeys();
    }
}

void KeyboardMain::hidCallback(EventType event, uint16_t arg) {
    eventsQueue.push_back({ event, arg });
}

void KeyboardMain::processPressedKeys() {
    switch (state) {
        case NORMAL:
            if (isPressed(KC_FN)) {
                ledController.setAllKeys(COLOR_BLACK);
                ledController.setKeyColor(keycodeToIndex[KC_F1], settings.ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F2], settings.ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F3], settings.ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F4], settings.ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F5], settings.ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F6], settings.ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F7], settings.ledColor);
                ledController.toggleFrame();
                state = FN_MODE;
                // fall through
            } else {
                keyboardHid.sendKeycodes(pressedKeycodes);
                break;
            }
        case FN_MODE:
            if (!isPressed(KC_FN)) {
                state = NORMAL;
                ledController.setAllKeys(settings.ledColor);
                ledController.toggleFrame();
                break;
            }
            keyboardHid.sendKeycodes(pressedKeycodes);
            break;
    }
}

void KeyboardMain::processVendorCommand() {
    uint8_t responseLength = 0;
    VendorResponse response { keyboardHid.vendorCommandData[0] };
    switch (keyboardHid.vendorCommandData[1]) {
        case 0x01:
            if (settings.ledsEnabled)
                ledController.setAllKeys(settings.ledColor);
            else
                ledController.setAllKeys(COLOR_BLACK);

            settings.ledsEnabled = !settings.ledsEnabled;
            response.data[0] = 0;
            response.data[1] = settings.ledsEnabled ? 1 : 0;
            responseLength = 2;
            break;
        case 0x02:
            settings.ledsEnabled = false;
            ledController.setAllKeys(COLOR_BLACK);
            for (uint8_t i=0; i < 104; i++) {
                if (keyboardHid.vendorCommandData[2 + i / 8] & (1 << i % 8))
                    ledController.setKeyColor(i, settings.ledColor);
            }
            ledController.toggleFrame();
            response.data[0] = 0;
            responseLength = 1;
            break;
        case 0x03:
            settings.ledColor.r = keyboardHid.vendorCommandData[2];
            settings.ledColor.g = keyboardHid.vendorCommandData[3];
            settings.ledColor.b = keyboardHid.vendorCommandData[4];
            response.data[0] = 0;
            responseLength = 1;
            break;
        case 0xFF:
            activateBootloader();
            break;
    }
    if (responseLength > 0)
        keyboardHid.sendVendor((uint8_t*)&response, responseLength + 1);
}

void KeyboardMain::activateBootloader() {
    keyboardHid.disconnect();
    ledController.setAllKeys({ 0xFF, 0, 0 });
    ledController.toggleFrame();
    IAP::invokeIsp();
}

bool KeyboardMain::isPressed(uint16_t keycode) {
    return pressedKeycodes.count(keycode) > 0;
}
