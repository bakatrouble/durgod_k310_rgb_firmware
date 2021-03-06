//
// Created by bakatrouble on 19/10/2021.
//

#ifndef DURGOD_K310_RGB_FIRMWARE_KEYBOARDMAIN_H
#define DURGOD_K310_RGB_FIRMWARE_KEYBOARDMAIN_H

#include <mbed.h>
#include <vector>
#include <deque>
#include <types.h>
#include <parallel_hashmap/phmap.h>
#include "LEDController.h"
#include "colors.h"
#include "KeyboardHID.h"

using phmap::flat_hash_set;

class KeyboardMain {
public:
    void init();
    void loop();
    void hidCallback(EventType event, uint16_t arg);

protected:
    void scanKeys();
    void processEvents();
    void processPressedKeys();
    void processVendorCommand();
    bool processCustomKeycodes();
    void runTimerEvents();

    void drawBacklight();

    void activateBootloader();

    bool isPressed(uint16_t keycode);

    LEDController ledController;
    KeyboardHID keyboardHid;
    Timer timer;

    State state = NORMAL;
    Settings settings;
    std::deque<KeyboardEvent> eventsQueue = std::deque<KeyboardEvent>(10);
    flat_hash_set<uint16_t> pressedKeycodes = flat_hash_set<uint16_t>(104);
    flat_hash_set<uint16_t> turboKeys = flat_hash_set<uint16_t>(104);

    DigitalOut led_num = DigitalOut(LED_NUMLOCK_PIN, 1);
    DigitalOut led_caps = DigitalOut(LED_CAPSLOCK_PIN, 1);
    DigitalOut led_scroll = DigitalOut(LED_SCROLLLOCK_PIN, 1);
    DigitalOut led_lock = DigitalOut(LED_WINLOCK_PIN, 1);
    DigitalOut led_app = DigitalOut(LED_APP_PIN, 1);
    BusOut cols = BusOut(colPins[0], colPins[1], colPins[2], colPins[3], colPins[4], colPins[5], colPins[6], colPins[7], colPins[8], colPins[9], colPins[10], colPins[11], colPins[12], colPins[13], colPins[14], colPins[15]);
    BusIn rows = BusIn(rowPins[0], rowPins[1], rowPins[2], rowPins[3], rowPins[4], rowPins[5], rowPins[6], rowPins[7]);
};


#endif //DURGOD_K310_RGB_FIRMWARE_KEYBOARDMAIN_H
