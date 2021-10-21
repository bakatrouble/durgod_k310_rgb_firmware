//
// Created by bakatrouble on 18/10/2021.
//

#ifndef DURGOD_K310_RGB_FIRMWARE_LEDCONTROLLER_H
#define DURGOD_K310_RGB_FIRMWARE_LEDCONTROLLER_H

#include <mbed.h>
#include "i2c_api.h"

#include "defines.h"

#define ISSI_ADDR_DEFAULT 0x74

#define ISSI_REG_CONFIG  0x00
#define ISSI_REG_CONFIG_PICTUREMODE 0x00
#define ISSI_REG_CONFIG_AUTOPLAYMODE 0x08
#define ISSI_REG_CONFIG_AUDIOPLAYMODE 0x18

#define ISSI_CONF_PICTUREMODE 0x00
#define ISSI_CONF_AUTOFRAMEMODE 0x04
#define ISSI_CONF_AUDIOMODE 0x08

#define ISSI_REG_PICTUREFRAME  0x01

#define ISSI_REG_SHUTDOWN 0x0A
#define ISSI_REG_AUDIOSYNC 0x06

#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_BANK_FUNCTIONREG 0x0B    // helpfully called 'page nine'

#define ISSI_PRIMARY_BUFFER 0
#define ISSI_SECONDARY_BUFFER 1

#define ENABLE_OFFSET 0x00
#define COLOR_OFFSET 0x24

class LEDController {
public:
    void init();
    void display();
    void setKeyColor(uint8_t idx, Color color);
    void setAllKeys(Color color);

protected:
    void callFunction(uint8_t functionId, uint8_t arg);
    void setDriversPower(bool enabled);
    void setDriversConfig(uint8_t value);
    void setAudioSync(bool enabled);
    void selectBank(uint8_t driver, uint8_t bank);
    void writeRegister8(uint8_t driver, uint8_t bank, uint8_t reg, uint8_t data);
    void writeBytes(uint8_t driver, uint8_t reg, uint8_t n, uint8_t *data);
    void writeBuffer(uint8_t frame);
    uint8_t inactiveFrame() const {
        return activeFrame == ISSI_PRIMARY_BUFFER ? ISSI_SECONDARY_BUFFER : ISSI_PRIMARY_BUFFER;
    }
    void lowLevelClear(uint8_t frame);

    I2C i2c = I2C(P0_5, P0_4);
    uint8_t activeFrame = ISSI_PRIMARY_BUFFER;
    const uint8_t addresses[4] = { 0x74, 0x75, 0x76, 0x77 };
    uint8_t ledBuffer[4][6][24] = {};
};


#endif //DURGOD_K310_RGB_FIRMWARE_LEDCONTROLLER_H
