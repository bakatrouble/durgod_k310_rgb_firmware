#include <USBSerial.h>
#include <mbed.h>
#include <modules/LEDController.h>
#include "defines.h"
#include "kbd/USBKeyboard2.h"
#include "gen.h"
#include "iap.h"
#include "defines.h"
#include "colors.h"

//USBSerial serial;
USBKeyboard2 kbd;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
static LEDController ledController;
DigitalOut led_num(LED_NUMLOCK_PIN, 1);
DigitalOut led_caps(LED_CAPSLOCK_PIN, 1);
DigitalOut led_scroll(LED_SCROLLLOCK_PIN, 1);
DigitalOut led_lock(LED_WINLOCK_PIN, 1);
DigitalOut led_app(LED_APP_PIN, 1);
BusOut cols(colPins[0], colPins[1], colPins[2], colPins[3], colPins[4], colPins[5], colPins[6], colPins[7], colPins[8], colPins[9], colPins[10], colPins[11], colPins[12], colPins[13], colPins[14], colPins[15]);
BusIn rows(rowPins[0], rowPins[1], rowPins[2], rowPins[3], rowPins[4], rowPins[5], rowPins[6], rowPins[7]);
#pragma clang diagnostic pop

static bool pressedKeys[105];
static bool changedClasses[2];
static bool winLocked = false, ledsEnabled = true;
static Color ledColor = { 0xFF, 0xFF, 0xFF };


bool scanKeys() {
    bool changed = false;
    uint8_t row, col;
    for (col=0; col < 16; col++) {
        cols = ~(1 << col);
        for (row=0; row < 8; row++) {
            uint8_t idx = matrixToIndex[row][col];
            if ((rows & (1 << row)) == 0) {
                if (!pressedKeys[idx]) {
                    pressedKeys[idx] = true;
                    changed = true;
                }
            } else {
                if (pressedKeys[idx]) {
                    pressedKeys[idx] = false;
                    changed = true;
                }
            }
        }
        cols = 1;
    }
    return changed;
}

void initHardware() {
    rows.mode(PullUp);
    cols = 1;
    ledController.init();
    led_num = 0;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main() {
    initHardware();

    ledController.setAllKeys(ledColor);
    ledController.toggleFrame();

    bool fnLayer = false;

    while (true) {
        auto changed = scanKeys();
        if (changed) {
            bool fnPressed = pressedKeys[keycodeToIndex[KC_FN0]];
            if (!fnLayer && fnPressed) {
                ledController.setAllKeys(COLOR_BLACK);
                ledController.setKeyColor(keycodeToIndex[KC_F1], ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F2], ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F3], ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F4], ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F5], ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F6], ledColor);
                ledController.setKeyColor(keycodeToIndex[KC_F7], ledColor);
                ledController.toggleFrame();
                fnLayer = true;
            }
            if (fnLayer && !fnPressed) {
                ledController.setAllKeys(ledColor);
                ledController.toggleFrame();
                fnLayer = false;
            }
            kbd.sendKeycodes(pressedKeys, fnLayer ? 1 : 0);
//            testLed();
        }

        uint8_t lockStatus = kbd.lockStatus();
        led_num = !(lockStatus & 0x1);
        led_caps = !(lockStatus & 0x2);
        led_scroll = !(lockStatus & 0x4);
        led_app = kbd.statusLed;

        if (!kbd.vendorCommandProcessed) {
            uint8_t responseLength = 0;
            VendorResponse response {kbd.vendorCommandData[0] };
            switch (kbd.vendorCommandData[1]) {
                case 0x01:
                    if (ledsEnabled)
                        ledController.setAllKeys(ledColor);
                    else
                        ledController.setAllKeys(COLOR_BLACK);

                    ledsEnabled = !ledsEnabled;
                    response.data[0] = 0;
                    response.data[1] = ledsEnabled ? 1 : 0;
                    responseLength = 2;
                    break;
                case 0x02:
                    ledsEnabled = false;
                    ledController.setAllKeys(COLOR_BLACK);
                    for (uint8_t i=0; i < 104; i++) {
                        if (kbd.vendorCommandData[2 + i / 8] & (1 << i % 8))
                            ledController.setKeyColor(i, ledColor);
                    }
                    ledController.toggleFrame();
                    response.data[0] = 0;
                    responseLength = 1;
                    break;
                case 0x03:
                    ledColor.r = kbd.vendorCommandData[2];
                    ledColor.g = kbd.vendorCommandData[3];
                    ledColor.b = kbd.vendorCommandData[4];
                    response.data[0] = 0;
                    responseLength = 1;
                    break;
                case 0xFF:
                    kbd.disconnect();
                    IAP::invokeIsp();
                    break;
            }
            if (responseLength > 0)
                kbd.sendVendor((uint8_t*)&response, responseLength + 1);
            kbd.vendorCommandProcessed = true;
        }

        wait(.005);
    }
}
#pragma clang diagnostic pop
