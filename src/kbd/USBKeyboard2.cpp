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

#define MODMASK_LCTRL 0x1
#define MODMASK_LSHIFT 0x2
#define MODMASK_LALT 0x4
#define MODMASK_LGUI 0x8
#define MODMASK_RCTRL 0x10
#define MODMASK_RSHIFT 0x20
#define MODMASK_RALT 0x40
#define MODMASK_RGUI 0x80

#define NKRO_EPSIZE 32

const uint8_t * USBKeyboard2::reportDesc() {
    static const uint8_t reportDescriptor[] = {
            USAGE_PAGE(1), 0x01,                    // Generic Desktop
            USAGE(1), 0x06,                         // Keyboard
            COLLECTION(1), 0x01,                    // Application
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
                INPUT(1), 0x02,                         // Constant


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

//                REPORT_COUNT(1), (NKRO_EPSIZE-1)*8,
//                REPORT_SIZE(1), 0x01,
//                LOGICAL_MINIMUM(1), 0x00,
//                LOGICAL_MAXIMUM(1), 0x01,
//                USAGE_PAGE(1), 0x07,                    // Key Codes
//                USAGE_MINIMUM(1), 0x00,
//                USAGE_MAXIMUM(1), (NKRO_EPSIZE-1)*8-1,
//                INPUT(1), 0x02,
            END_COLLECTION(0),
            };
    reportLength = sizeof(reportDescriptor);
    return reportDescriptor;
}


bool USBKeyboard2::EPINT_OUT_callback() {
    uint32_t bytesRead = 0;
    uint8_t led[65];
    USBDevice::readEP(EPINT_OUT, led, &bytesRead, MAX_HID_REPORT_SIZE);

    // we take led[1] because led[0] is the report ID
    lock_status = led[1] & 0x07;

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
            C_RESERVED | C_SELF_POWERED,        // bmAttributes
            C_POWER(0),                         // bMaxPower

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

void USBKeyboard2::sendKeycodes(bool pressedKeys[]) {
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
    uint8_t ptr = 3;
    for (uint8_t idx=0; idx < 104; idx++) {
        if (pressedKeys[idx]) {
            if (ptr < 9) {
                report.data[ptr++] = indexToKeycode[idx];
            } else {
                break;
            }
        }
    }
    send(&report);
}
