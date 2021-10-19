//
// Created by bakatrouble on 19/10/2021.
//

#ifndef DURGOD_K310_RGB_FIRMWARE_TYPES_H
#define DURGOD_K310_RGB_FIRMWARE_TYPES_H

#include "colors.h"

enum EventType {
    KEY_PRESSED,
    KEY_RELEASED,
    VENDOR_COMMAND_RECEIVED,
    LEDS_RECEIVED,
};

enum State {
    NORMAL,
    FN_MODE,
};

struct KeyboardEvent {
    EventType event;
    uint16_t arg = 0;
};

struct Settings {
    Color ledColor = COLOR_WHITE;
    bool ledsEnabled = true;
    bool winLock = false;
    bool keysLocked = false;
    uint8_t brightness = 10;
};

#endif //DURGOD_K310_RGB_FIRMWARE_TYPES_H
