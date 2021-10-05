#include <USBSerial.h>
#include "mbed.h"
#include "defines.h"
#include "kbd/USBKeyboard2.h"
#include "IS31FL3731/IS31FL3731.h"
#include "gen.h"

//USBSerial serial;
USBKeyboard2 kbd(0xD60D, 0x3100, 0x0004);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
IS31FL3731 ledDrivers;
DigitalOut led_num(LED_NUMLOCK_PIN, 1);
DigitalOut led_caps(LED_CAPSLOCK_PIN, 1);
DigitalOut led_scroll(LED_SCROLLLOCK_PIN, 1);
DigitalOut led_lock(LED_WINLOCK_PIN, 1);
DigitalOut led_app(LED_APP_PIN, 1);
BusOut cols(colPins[0], colPins[1], colPins[2], colPins[3], colPins[4], colPins[5], colPins[6], colPins[7], colPins[8], colPins[9], colPins[10], colPins[11], colPins[12], colPins[13], colPins[14], colPins[15]);
BusIn rows(rowPins[0], rowPins[1], rowPins[2], rowPins[3], rowPins[4], rowPins[5], rowPins[6], rowPins[7]);
#pragma clang diagnostic pop

static bool pressedKeys[105];
static bool fnLayer = false, winLocked = false;

void enableLed(uint8_t idx) {
    ledDrivers.setLEDPWM(indexToLed[idx].driver, indexToLed[idx].r, 0xFF);
    ledDrivers.setLEDPWM(indexToLed[idx].driver, indexToLed[idx].g, 0xFF);
    ledDrivers.setLEDPWM(indexToLed[idx].driver, indexToLed[idx].b, 0xFF);
}

void disableLed(uint8_t idx) {
    ledDrivers.setLEDPWM(indexToLed[idx].driver, indexToLed[idx].r, 0);
    ledDrivers.setLEDPWM(indexToLed[idx].driver, indexToLed[idx].g, 0);
    ledDrivers.setLEDPWM(indexToLed[idx].driver, indexToLed[idx].b, 0);
}


bool scanKeys() {
    bool changed = false;
    uint8_t row, col;
    for (col=0; col < 16; col++) {
        cols = ~(1 << col);
        for (row=0; row < 8; row++) {
            uint8_t idx = matrixToIndex[row][col];
            if ((rows & (1 << row)) == 0) {
                if (!pressedKeys[idx]) {
                    disableLed(idx);
                    pressedKeys[idx] = true;
                    changed = true;
                }
            } else {
                if (pressedKeys[idx]) {
                    enableLed(idx);
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
    ledDrivers.init();
    led_num = 0;
}

void enableAllLeds() {
    for (auto idx : indexToLed) {
        ledDrivers.setLEDPWM(idx.driver, idx.r, 0xFF);
        ledDrivers.setLEDPWM(idx.driver, idx.g, 0xFF);
        ledDrivers.setLEDPWM(idx.driver, idx.b, 0xFF);
    }
}

void disableAllLeds() {
    ledDrivers.clear(0);
    ledDrivers.clear(1);
    ledDrivers.clear(2);
    ledDrivers.clear(3);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main() {
    initHardware();
    enableAllLeds();

    while (true) {
        auto changed = scanKeys();
        if (changed)
            kbd.sendKeycodes(pressedKeys);

        uint8_t lockStatus = kbd.lockStatus();
        led_num = !(lockStatus & 0x1);
        led_caps = !(lockStatus & 0x2);
        led_scroll = !(lockStatus & 0x4);
    }
}
#pragma clang diagnostic pop
