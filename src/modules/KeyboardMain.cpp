//
// Created by bakatrouble on 19/10/2021.
//

#include <iap.h>
#include "KeyboardMain.h"
#include "gen.h"

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
            if ((rows & (1 << row)) == 0) {
                if (!pressedKeys[idx]) {
                    eventsQueue.push_back({ EventType::KEY_PRESSED, idx });
                }
            } else {
                if (pressedKeys[idx]) {
                    pressedKeys[idx] = false;
                    eventsQueue.push_back({ EventType::KEY_RELEASED, idx });
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
                pressedKeys[event.arg] = true;
//                led_app = !led_app;
                keysChanged = true;
                break;
            case KEY_RELEASED:
                pressedKeys[event.arg] = false;
//                led_app = !led_app;
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

void KeyboardMain::hidCallback(EventType event, uint8_t arg) {
    eventsQueue.push_back({ event, arg });
}

void KeyboardMain::processPressedKeys() {
    switch (state) {
        case NORMAL:
            if (isPressed(KC_FN0)) {
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
                keyboardHid.sendKeycodes(pressedKeys, 0);
                break;
            }
        case FN_MODE:
            if (!isPressed(KC_FN0)) {
                state = NORMAL;
                break;
            }
            keyboardHid.sendKeycodes(pressedKeys, 1);
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
            keyboardHid.disconnect();
            IAP::invokeIsp();
            break;
    }
    if (responseLength > 0)
        keyboardHid.sendVendor((uint8_t*)&response, responseLength + 1);
}

bool KeyboardMain::isPressed(uint8_t keycode) {
    return pressedKeys[keycodeToIndex[keycode]];
}
