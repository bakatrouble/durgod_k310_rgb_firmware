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

#ifndef USBKEYBOARD_H
#define USBKEYBOARD_H

#include "USBHID.h"
#include "Stream.h"

class USBKeyboard2: public USBHID {
public:
    USBKeyboard2(uint16_t vendor_id = 0xD60D, uint16_t product_id = 0x3100, uint16_t product_release = 0x0004):
            USBHID(0, 0, vendor_id, product_id, product_release, false) {
        lock_status = 0;
        connect();
    };

    /*
    * To define the report descriptor. Warning: this method has to store the length of the report descriptor in reportLength.
    *
    * @returns pointer to the report descriptor
    */
    const uint8_t * reportDesc() override;

    /*
    * Called when a data is received on the OUT endpoint. Useful to switch on LED of LOCK keys
    *
    * @returns if handle by subclass, return true
    */
    bool EPINT_OUT_callback() override;

    /**
    * Read status of lock keys. Useful to switch-on/off leds according to key pressed. Only the first three bits of the result is important:
    *   - First bit: NUM_LOCK
    *   - Second bit: CAPS_LOCK
    *   - Third bit: SCROLL_LOCK
    *
    * @returns status of lock keys
    */
    uint8_t lockStatus();

    void sendKeycodes(bool pressedKeys[]);

protected:
    /*
    * Get configuration descriptor
    *
    * @returns pointer to the configuration descriptor
    */
    const uint8_t * configurationDesc() override;

    const uint8_t * stringIproductDesc() override {
        static const uint8_t stringIproductDescriptor[] = {
                0x4E,
                STRING_DESCRIPTOR,
                'D', 0, 'U', 0, 'R', 0, 'G', 0, 'O', 0, 'D', 0, ' ', 0, 'T', 0,
                'a', 0, 'u', 0, 'r', 0, 'u', 0, 's', 0, ' ', 0, 'K', 0, '3', 0,
                '1', 0, '0', 0, ' ', 0, 'R', 0, 'G', 0, 'B', 0, ' ', 0, 'N', 0,
                'e', 0, 'b', 0, 'u', 0, 'l', 0, 'a', 0, ' ', 0, '(', 0, 'C', 0,
                'u', 0, 's', 0, 't', 0, 'o', 0, 'm', 0, ')', 0,
        };
        return stringIproductDescriptor;
    }

    const uint8_t * stringImanufacturerDesc() override {
        static const uint8_t stringImanufacturerDescriptor[] = {
                0x22,
                STRING_DESCRIPTOR,
                'H', 0, 'o', 0, 'k', 0, 's', 0, 'i', 0, ' ', 0, 'T', 0, 'e', 0,
                'c', 0, 'h', 0, 'n', 0, 'o', 0, 'l', 0, 'o', 0, 'g', 0, 'y', 0,
        };
        return stringImanufacturerDescriptor;
    }

private:
    uint8_t configurationDescriptor[41];
    uint8_t lock_status;
};

#endif
