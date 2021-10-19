//
// Created by bakatrouble on 19/10/2021.
//

#ifndef DURGOD_K310_RGB_FIRMWARE_KEYBOARDHID_H
#define DURGOD_K310_RGB_FIRMWARE_KEYBOARDHID_H

#include <mbed.h>
#include <unordered_set>
#include "USBHID.h"
#include "Stream.h"
#include "types.h"

class KeyboardMain;

#define HID_GET_PROTOCOL (0x3)
#define HID_SET_PROTOCOL (0xb)

const uint8_t BOOT_PROTOCOL = 0x00;
const uint8_t REPORT_PROTOCOL = 0x01;

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

static const uint8_t stringIproductDescriptor[] = {
        0x4E,
        STRING_DESCRIPTOR,
        'D', 0, 'U', 0, 'R', 0, 'G', 0, 'O', 0, 'D', 0, ' ', 0, 'T', 0,
        'a', 0, 'u', 0, 'r', 0, 'u', 0, 's', 0, ' ', 0, 'K', 0, '3', 0,
        '1', 0, '0', 0, ' ', 0, 'R', 0, 'G', 0, 'B', 0, ' ', 0, 'N', 0,
        'e', 0, 'b', 0, 'u', 0, 'l', 0, 'a', 0, ' ', 0, '(', 0, 'C', 0,
        'u', 0, 's', 0, 't', 0, 'o', 0, 'm', 0, ')', 0,
};

static const uint8_t stringImanufacturerDescriptor[] = {
        0x22,
        STRING_DESCRIPTOR,
        'H', 0, 'o', 0, 'k', 0, 's', 0, 'i', 0, ' ', 0, 'T', 0, 'e', 0,
        'c', 0, 'h', 0, 'n', 0, 'o', 0, 'l', 0, 'o', 0, 'g', 0, 'y', 0,
};


static const uint8_t keyboardReportDescriptor[] = {
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

#define DEFAULT_CONFIGURATION (1)
#define TOTAL_DESCRIPTOR_LENGTH ((1 * CONFIGURATION_DESCRIPTOR_LENGTH) \
+ (1 * INTERFACE_DESCRIPTOR_LENGTH) \
+ (1 * HID_DESCRIPTOR_LENGTH) \
+ (2 * ENDPOINT_DESCRIPTOR_LENGTH))

const uint8_t keyboardConfigurationDescriptor[] = {
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
        (uint8_t)(LSB(sizeof(keyboardReportDescriptor))), // wDescriptorLength (LSB)
        (uint8_t)(MSB(sizeof(keyboardReportDescriptor))), // wDescriptorLength (MSB)

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

class KeyboardHID : public USBHID {
public:
    explicit KeyboardHID(uint16_t vendor_id = 0x2f68, uint16_t product_id = 0x0041, uint16_t product_release = 0x0114):
             USBHID(0, 0, vendor_id, product_id, product_release, false) {};

    void init();
    const uint8_t * reportDesc() override;
    bool EPINT_OUT_callback() override;
    void sendKeycodes(std::unordered_set<uint16_t> &pressedKeycodes);
    void sendVendor(uint8_t *data, uint32_t n);
    bool USBCallback_request() override;
    void setKeyboardMain(KeyboardMain *ptr);

    uint8_t vendorCommandData[0x3E]{};

protected:
    const uint8_t * configurationDesc() override;
    const uint8_t * stringIproductDesc() override;
    const uint8_t * stringImanufacturerDesc() override;

private:
    bool bootProtocol = true;
    KeyboardMain *keyboardMain;
};


#endif //DURGOD_K310_RGB_FIRMWARE_KEYBOARDHID_H
