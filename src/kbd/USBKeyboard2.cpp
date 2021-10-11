/* Copyright (c) 2010-2011 mbed.org, MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "stdint.h"

#include "kbd/USBKeyboard2.h"
#include "gen.h"

#define REPORT_ID_KEYBOARD 1
#define REPORT_ID_NKRO 2
#define REPORT_ID_CONSUMER 3
#define REPORT_ID_VENDOR 4

#define MODMASK_LCTRL 0x1
#define MODMASK_LSHIFT 0x2
#define MODMASK_LALT 0x4
#define MODMASK_LGUI 0x8
#define MODMASK_RCTRL 0x10
#define MODMASK_RSHIFT 0x20
#define MODMASK_RALT 0x40
#define MODMASK_RGUI 0x80

#define NKRO_EPSIZE 16

const uint8_t * USBKeyboard2::reportDesc() {
    static const uint8_t reportDescriptor[] = {
            USAGE_PAGE(1), 0x01,                        // Generic Desktop
            USAGE(1), 0x06,                             // Keyboard
            COLLECTION(1), 0x01,                        // Application
                REPORT_ID(1),       REPORT_ID_KEYBOARD,

                USAGE_PAGE(1), 0x07,                    // Key Codes
                USAGE_MINIMUM(1), 0xE0,
                USAGE_MAXIMUM(1), 0xE7,
                LOGICAL_MINIMUM(1), 0x00,
                LOGICAL_MAXIMUM(1), 0x01,
                REPORT_SIZE(1), 0x01,
                REPORT_COUNT(1), 0x08,
                INPUT(1), 0x02,                         // Data, Variable, Absolute
                REPORT_COUNT(1), 0x01,
                REPORT_SIZE(1), 0x08,
                INPUT(1), 0x01,                         // Constant


                REPORT_COUNT(1), 0x05,
                REPORT_SIZE(1), 0x01,
                USAGE_PAGE(1), 0x08,                    // LEDs
                USAGE_MINIMUM(1), 0x01,
                USAGE_MAXIMUM(1), 0x05,
                OUTPUT(1), 0x02,                        // Data, Variable, Absolute
                REPORT_COUNT(1), 0x01,
                REPORT_SIZE(1), 0x03,
                OUTPUT(1), 0x03,                        // Constant

                REPORT_COUNT(1), 0x06,
                REPORT_SIZE(1), 0x08,
                LOGICAL_MINIMUM(1), 0x00,
                LOGICAL_MAXIMUM(1), 0x65,
                USAGE_PAGE(1), 0x07,                    // Key Codes  0x07
                USAGE_MINIMUM(1), 0x00,
                USAGE_MAXIMUM(1), 0x65,
                INPUT(1), 0x00,                         // Data, Array
            END_COLLECTION(0),

            // NKRO bitmap
            USAGE_PAGE(1), 0x01,                        // Generic Desktop
            USAGE(1), 0x06,                             // Keyboard
            COLLECTION(1), 0x01,                        // Application
                REPORT_ID(1),       REPORT_ID_NKRO,

                USAGE_PAGE(1), 0x07,                    // Key Codes
                USAGE_MINIMUM(1), 0xE0,
                USAGE_MAXIMUM(1), 0xE7,
                LOGICAL_MINIMUM(1), 0x00,
                LOGICAL_MAXIMUM(1), 0x01,
                REPORT_SIZE(1), 0x01,
                REPORT_COUNT(1), 0x08,
                INPUT(1), 0x02,                         // Data, Variable, Absolute
                REPORT_COUNT(1), 0x01,
                REPORT_SIZE(1), 0x08,
                INPUT(1), 0x01,                         // Constant


                REPORT_COUNT(1), 0x05,
                REPORT_SIZE(1), 0x01,
                USAGE_PAGE(1), 0x08,                    // LEDs
                USAGE_MINIMUM(1), 0x01,
                USAGE_MAXIMUM(1), 0x05,
                OUTPUT(1), 0x02,                        // Data, Variable, Absolute
                REPORT_COUNT(1), 0x01,
                REPORT_SIZE(1), 0x03,
                OUTPUT(1), 0x03,                        // Constant

                USAGE_PAGE(1), 0x07,                    // Key Codes  0x07
                REPORT_COUNT(1), (NKRO_EPSIZE-1)*8,
                REPORT_SIZE(1), 0x01,
                LOGICAL_MINIMUM(1), 0x00,
                LOGICAL_MAXIMUM(1), 0x01,
                USAGE_MINIMUM(1), 0x00,
                USAGE_MAXIMUM(1), (NKRO_EPSIZE-1)*8-1,
                INPUT(1), 0x02,
            END_COLLECTION(0),

            // Media Control
            USAGE_PAGE(1), 0x0C,
            USAGE(1), 0x01,
            COLLECTION(1), 0x01,
                REPORT_ID(1), REPORT_ID_CONSUMER,
                LOGICAL_MINIMUM(1), 0x00,
                LOGICAL_MAXIMUM(2), 0xFF, 0x1F,
                USAGE_MINIMUM(1), 0x00,
                USAGE_MAXIMUM(2), 0xFF, 0x1F,
                REPORT_SIZE(1), 0x10,
                REPORT_COUNT(1), 0x01,
                INPUT(1), 0x00,
            END_COLLECTION(0),

            USAGE_PAGE(2), LSB(0xFF1C), MSB(0xFF1C),  // Vendor Specific?
            USAGE(1), 0x92,                                 // Vendor Usage 1
            COLLECTION(1), 0x01,                            // Application
                REPORT_ID(1), REPORT_ID_VENDOR,

                USAGE_MINIMUM(1), 0x00,
                USAGE_MAXIMUM(2), 0xFF, 0x00,
                LOGICAL_MINIMUM(1), 0x00,
                LOGICAL_MAXIMUM(2), 0xFF, 0x00,
                REPORT_SIZE(1), 0x08,
                REPORT_COUNT(1), 0x3F,
                OUTPUT(1), 0x00,

                USAGE_MINIMUM(1), 0x00,
                USAGE_MAXIMUM(1), 0xFF,
                INPUT(1), 0x00,
            END_COLLECTION(0),
            };
    reportLength = sizeof(reportDescriptor);
    return reportDescriptor;
}


bool USBKeyboard2::EPINT_OUT_callback() {
    uint32_t bytesRead = 0;
    uint8_t report[0x3F];
    USBDevice::readEP(EPINT_OUT, report, &bytesRead, MAX_HID_REPORT_SIZE);

    if (report[0] == REPORT_ID_KEYBOARD || report[0] == REPORT_ID_NKRO) {
        lock_status = report[1] & 0x07;
    }

    if (report[0] == REPORT_ID_VENDOR) {
        memcpy(vendorCommandData, &report[1], 0x3F);
        vendorCommandProcessed = false;
    }

    statusLed = !statusLed;


    // We activate the endpoint to be able to recceive data
    if (!readStart(EPINT_OUT, MAX_HID_REPORT_SIZE))
        return false;
    return true;
}

uint8_t USBKeyboard2::lockStatus() {
    return lock_status;
}


#define DEFAULT_CONFIGURATION (1)
#define TOTAL_DESCRIPTOR_LENGTH ((1 * CONFIGURATION_DESCRIPTOR_LENGTH) \
+ (1 * INTERFACE_DESCRIPTOR_LENGTH) \
+ (1 * HID_DESCRIPTOR_LENGTH) \
+ (2 * ENDPOINT_DESCRIPTOR_LENGTH))

const uint8_t * USBKeyboard2::configurationDesc() {
    uint8_t configurationDescriptorTemp[] = {
            CONFIGURATION_DESCRIPTOR_LENGTH,    // bLength
            CONFIGURATION_DESCRIPTOR,           // bDescriptorType
            LSB(TOTAL_DESCRIPTOR_LENGTH),       // wTotalLength (LSB)
            MSB(TOTAL_DESCRIPTOR_LENGTH),       // wTotalLength (MSB)
            0x01,                               // bNumInterfaces
            DEFAULT_CONFIGURATION,              // bConfigurationValue
            0x00,                               // iConfiguration
            C_RESERVED | C_REMOTE_WAKEUP,       // bmAttributes
            C_POWER(500),                       // bMaxPower

                INTERFACE_DESCRIPTOR_LENGTH,        // bLength
                INTERFACE_DESCRIPTOR,               // bDescriptorType
                0x00,                               // bInterfaceNumber
                0x00,                               // bAlternateSetting
                0x02,                               // bNumEndpoints
                HID_CLASS,                          // bInterfaceClass
                HID_SUBCLASS_BOOT,                  // bInterfaceSubClass
                HID_PROTOCOL_KEYBOARD,              // bInterfaceProtocol
                0x00,                               // iInterface

                    HID_DESCRIPTOR_LENGTH,              // bLength
                    HID_DESCRIPTOR,                     // bDescriptorType
                    LSB(HID_VERSION_1_11),              // bcdHID (LSB)
                    MSB(HID_VERSION_1_11),              // bcdHID (MSB)
                    0x00,                               // bCountryCode
                    0x01,                               // bNumDescriptors
                    REPORT_DESCRIPTOR,                  // bDescriptorType
                    (uint8_t)(LSB(reportDescLength())), // wDescriptorLength (LSB)
                    (uint8_t)(MSB(reportDescLength())), // wDescriptorLength (MSB)

                    ENDPOINT_DESCRIPTOR_LENGTH,         // bLength
                    ENDPOINT_DESCRIPTOR,                // bDescriptorType
                    PHY_TO_DESC(EPINT_IN),              // bEndpointAddress
                    E_INTERRUPT,                        // bmAttributes
                    LSB(MAX_PACKET_SIZE_EPINT),         // wMaxPacketSize (LSB)
                    MSB(MAX_PACKET_SIZE_EPINT),         // wMaxPacketSize (MSB)
                    1,                                  // bInterval (milliseconds)

                    ENDPOINT_DESCRIPTOR_LENGTH,         // bLength
                    ENDPOINT_DESCRIPTOR,                // bDescriptorType
                    PHY_TO_DESC(EPINT_OUT),             // bEndpointAddress
                    E_INTERRUPT,                        // bmAttributes
                    LSB(MAX_PACKET_SIZE_EPINT),         // wMaxPacketSize (LSB)
                    MSB(MAX_PACKET_SIZE_EPINT),         // wMaxPacketSize (MSB)
                    1,                                  // bInterval (milliseconds)
    };
    MBED_ASSERT(sizeof(configurationDescriptorTemp) == sizeof(configurationDescriptor));
    memcpy(configurationDescriptor, configurationDescriptorTemp, sizeof(configurationDescriptor));
    return configurationDescriptor;
}

void USBKeyboard2::sendKeycodes(bool pressedKeys[], uint8_t layer) {
    uint8_t modifiers = 0;
    if (pressedKeys[keycodeToIndex[KC_LCTL]])
        modifiers |= MODMASK_LCTRL;
    if (pressedKeys[keycodeToIndex[KC_LGUI]])
        modifiers |= MODMASK_LGUI;
    if (pressedKeys[keycodeToIndex[KC_LALT]])
        modifiers |= MODMASK_LALT;
    if (pressedKeys[keycodeToIndex[KC_LSFT]])
        modifiers |= MODMASK_LSHIFT;
    if (pressedKeys[keycodeToIndex[KC_RALT]])
        modifiers |= MODMASK_RALT;
    if (pressedKeys[keycodeToIndex[KC_RCTL]])
        modifiers |= MODMASK_RCTRL;
    if (pressedKeys[keycodeToIndex[KC_RSFT]])
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
    for (uint8_t idx=0; idx < 104; idx++) {
        if (pressedKeys[idx]) {
            uint8_t keycode = indexToKeycode[layer][idx];
            if (indexToKeycodeClass[layer][idx] == KCLASS_GENERIC) {
                if (ptr < 9) {
                    report.data[ptr++] = keycode;
                } else {
                    nkroReport.data[3 + keycode / 8] |= 1 << keycode % 8;
                }
            } else {
                mediaReport.data[1] = keycode;
                send(&mediaReport);
            }
        }
    }
    send(&report);
    send(&nkroReport);
    if (mediaReport.data[1] == 0) {
        send(&mediaReport);
    }
}

void USBKeyboard2::sendVendor(uint8_t *data, uint32_t n) {
    HID_REPORT report = {
            n+1,
            { REPORT_ID_VENDOR }
    };
    memcpy(&report.data[1], data, n);
    send(&report);
}

const uint8_t BOOT_PROTOCOL = 0x00;
const uint8_t REPORT_PROTOCOL = 0x01;

bool USBKeyboard2::USBCallback_request() {
    bool success = USBHID::USBCallback_request();
    if (success)
        return success;

    CONTROL_TRANSFER * transfer = getTransferPtr();

    if (transfer->setup.bmRequestType.Type == CLASS_TYPE) {
        switch (transfer->setup.bRequest) {
            case HID_GET_PROTOCOL:
                transfer->remaining = 1;
                transfer->ptr = (uint8_t*)&(boot_protocol ? BOOT_PROTOCOL : REPORT_PROTOCOL);
                transfer->direction = DEVICE_TO_HOST;
                success = true;
                break;
            case HID_SET_PROTOCOL:
                boot_protocol = transfer->setup.wValue == 0x00;
                success = true;
                break;
        }
    }

    return success;
}
