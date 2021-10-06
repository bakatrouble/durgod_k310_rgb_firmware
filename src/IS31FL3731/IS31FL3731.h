#ifndef _ADAFRUIT_IS31FL3731_H_
#define _ADAFRUIT_IS31FL3731_H_

#include "mbed.h"
#include "i2c_api.h"


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

class IS31FL3731  {
public:
    bool init();
    void clear(uint8_t driver);

    void setLEDPWM(uint8_t driver, uint8_t lednum, uint8_t pwm, uint8_t bank = 0);
    void displayFrame(uint8_t driver, uint8_t frame);


protected:
    void selectBank(uint8_t driver, uint8_t bank);
    void writeRegister8(uint8_t driver, uint8_t bank, uint8_t reg, uint8_t data);
    void writeBytes(uint8_t address, uint8_t reg, uint8_t len, uint8_t *data);
    void displayFrame(uint8_t frame);
    I2C i2c = I2C(P0_5, P0_4);
    const uint8_t addresses[4] = { 0x74, 0x75, 0x76, 0x77 };
};

#endif