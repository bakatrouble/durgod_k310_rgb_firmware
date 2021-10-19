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
                if (!(settings.winLock && event.arg == KC_LGUI))
                    pressedKeycodes.insert(event.arg);

                if (!processCustomKeycodes())
                    keysChanged = true;

                break;
            case KEY_RELEASED:
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
                state = FN_MODE;
                drawBacklight();
                pressedKeycodes.clear();
                pressedKeycodes.insert(KC_FN);
                // fall through
            } else {
                if (!settings.keysLocked)
                    keyboardHid.sendKeycodes(pressedKeycodes);
                break;
            }
        case FN_MODE:
            if (!isPressed(KC_FN)) {
                state = NORMAL;
                drawBacklight();
                pressedKeycodes.clear();
                break;
            }
            if (!settings.keysLocked)
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

bool KeyboardMain::processCustomKeycodes() {
    if (pressedKeycodes.count(KC_BOOTLOADER1) > 0 && pressedKeycodes.contains(KC_BOOTLOADER2) > 0) {
        activateBootloader();
        return true;
    }
    if (pressedKeycodes.count(KC_BACKLIGHT_DISABLE) > 0) {
        settings.ledsEnabled = false;
        drawBacklight();
        return true;
    }
    if (pressedKeycodes.count(KC_BACKLIGHT_ENABLE) > 0) {
        settings.ledsEnabled = true;
        drawBacklight();
        return true;
    }
    if (pressedKeycodes.count(KC_WIN_LOCK) > 0) {
        settings.winLock = !settings.winLock;
        led_lock = !settings.winLock;
        return true;
    }
    if (pressedKeycodes.count(KC_KEYBOARD_LOCK) > 0) {
        settings.keysLocked = !settings.keysLocked;
        led_app = !settings.keysLocked;
        return true;
    }
    if (pressedKeycodes.count(KC_BACKLIGHT_BRDOWN) > 0) {
        if (settings.brightness > 1)
            settings.brightness--;
        drawBacklight();
        return true;
    }
    if (pressedKeycodes.count(KC_BACKLIGHT_BRUP) > 0) {
        if (settings.brightness < 10)
            settings.brightness++;
        drawBacklight();
        return true;
    }
    return false;
}

void KeyboardMain::drawBacklight() {
    ledController.setAllKeys(COLOR_BLACK);
    if (settings.ledsEnabled) {
        Color color = settings.ledColor.adjustBrightness(settings.brightness);

        switch (state) {
        case NORMAL:
            ledController.setAllKeys(color);
            break;
        case FN_MODE:
            Color redColor = COLOR_RED;
            redColor = redColor.adjustBrightness(settings.brightness);

            ledController.setKeyColor(keycodeToIndex[KC_F1], color);
            ledController.setKeyColor(keycodeToIndex[KC_F2], color);
            ledController.setKeyColor(keycodeToIndex[KC_F3], color);
            ledController.setKeyColor(keycodeToIndex[KC_F4], color);
            ledController.setKeyColor(keycodeToIndex[KC_F5], color);
            ledController.setKeyColor(keycodeToIndex[KC_F6], color);
            ledController.setKeyColor(keycodeToIndex[KC_F7], color);
            ledController.setKeyColor(keycodeToIndex[KC_LGUI], color);
            ledController.setKeyColor(keycodeToIndex[KC_INSERT], color);
            ledController.setKeyColor(keycodeToIndex[KC_DELETE], color);
            ledController.setKeyColor(keycodeToIndex[KC_F12], color);
            ledController.setKeyColor(keycodeToIndex[KC_UP], color);
            ledController.setKeyColor(keycodeToIndex[KC_DOWN], color);
            ledController.setKeyColor(keycodeToIndex[KC_B], redColor);
            ledController.setKeyColor(keycodeToIndex[KC_L], redColor);
            break;
        }
    }
    ledController.toggleFrame();
}

void KeyboardMain::activateBootloader() {
    keyboardHid.disconnect();
    ledController.setAllKeys(COLOR_RED);
    ledController.toggleFrame();
    led_num = led_caps = led_scroll = led_lock = led_app = 0;
    IAP::invokeIsp();
}

bool KeyboardMain::isPressed(uint16_t keycode) {
    return pressedKeycodes.count(keycode) > 0;
}
