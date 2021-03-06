//
// Created by bakatrouble on 19/10/2021.
//

#include <layout.h>
#include "modules/KeyboardHID.h"
#include "modules/KeyboardMain.h"

void KeyboardHID::init() {
    connect();
}

const uint8_t *KeyboardHID::reportDesc() {
    reportLength = sizeof(keyboardReportDescriptor);
    return keyboardReportDescriptor;
}

bool KeyboardHID::EP1_OUT_callback() {
    uint32_t bytesRead = 0;
    uint8_t report[0x3F];
    USBDevice::readEP(EPINT_OUT, report, &bytesRead, MAX_HID_REPORT_SIZE);

    if (keyboardMain != nullptr) {
        if (report[0] == REPORT_ID_KEYBOARD || report[0] == REPORT_ID_NKRO) {
            keyboardMain->hidCallback(LEDS_RECEIVED, report[1] & 0x07);
        }

        if (report[0] == REPORT_ID_VENDOR) {
            memcpy(vendorCommandData, &report[1], 0x3E);
            keyboardMain->hidCallback(VENDOR_COMMAND_RECEIVED, 0);
        }
    }

    // We activate the endpoint to be able to receive data
    if (!readStart(EPINT_OUT, MAX_HID_REPORT_SIZE))
        return false;
    return true;
}

void KeyboardHID::sendKeycodes(flat_hash_set<uint16_t> &pressedKeycodes) {
    uint8_t modifiers = 0;
    if (pressedKeycodes.count(KC_LCTRL) > 0)
        modifiers |= MODMASK_LCTRL;
    if (pressedKeycodes.count(KC_LGUI) > 0)
        modifiers |= MODMASK_LGUI;
    if (pressedKeycodes.count(KC_LALT) > 0)
        modifiers |= MODMASK_LALT;
    if (pressedKeycodes.count(KC_LSHIFT) > 0)
        modifiers |= MODMASK_LSHIFT;
    if (pressedKeycodes.count(KC_RALT) > 0)
        modifiers |= MODMASK_RALT;
    if (pressedKeycodes.count(KC_RCTRL) > 0)
        modifiers |= MODMASK_RCTRL;
    if (pressedKeycodes.count(KC_RSHIFT) > 0)
        modifiers |= MODMASK_RSHIFT;

    HID_REPORT report = {
            9,
            {
                REPORT_ID_KEYBOARD,
                modifiers,
                0,
                0, 0, 0, 0, 0, 0
            }
    };
    HID_REPORT nkroReport = {
            19,
            {
                REPORT_ID_NKRO,
                modifiers,
                0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
            }
    };
    HID_REPORT mediaReport = {
            3,
            {
                REPORT_ID_CONSUMER,
                0, 0
            }
    };
    uint8_t ptr = 3;
    for (auto keycode : pressedKeycodes) {
        if (keycode < 0x100) {
            if (ptr < 9) {
                report.data[ptr++] = keycode;
            } else {
                nkroReport.data[3 + keycode / 8] |= 1 << keycode % 8;
            }
        } else if (keycode < 0x200) {
            mediaReport.data[1] = keycode - 0x100;
            send(&mediaReport);
        }
    }
    send(&report);
    send(&nkroReport);
    if (mediaReport.data[1] == 0) {
        send(&mediaReport);
    }
}

void KeyboardHID::sendVendor(uint8_t *data, uint32_t n) {
    HID_REPORT report = {
            n+1,
            { REPORT_ID_VENDOR }
    };
    memcpy(&report.data[1], data, n);
    send(&report);
}

bool KeyboardHID::USBCallback_request() {
    bool success = USBHID::USBCallback_request();
    if (success)
        return success;

    CONTROL_TRANSFER * transfer = getTransferPtr();

    if (transfer->setup.bmRequestType.Type == CLASS_TYPE) {
        switch (transfer->setup.bRequest) {
            case HID_GET_PROTOCOL:
                transfer->remaining = 1;
                transfer->ptr = (uint8_t*)&(bootProtocol ? BOOT_PROTOCOL : REPORT_PROTOCOL);
                transfer->direction = DEVICE_TO_HOST;
                success = true;
                break;
            case HID_SET_PROTOCOL:
                bootProtocol = transfer->setup.wValue == 0x00;
                success = true;
                break;
        }
    }

    return success;
}

void KeyboardHID::setKeyboardMain(KeyboardMain *ptr) {
    keyboardMain = ptr;
}

const uint8_t *KeyboardHID::configurationDesc() {
    return keyboardConfigurationDescriptor;
}

const uint8_t *KeyboardHID::stringIproductDesc() {
    return stringIproductDescriptor;
}

const uint8_t *KeyboardHID::stringImanufacturerDesc() {
    return stringImanufacturerDescriptor;
}
