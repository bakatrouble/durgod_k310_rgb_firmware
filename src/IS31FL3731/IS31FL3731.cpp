#include "IS31FL3731.h"

bool IS31FL3731::init() {
    uint8_t i;
    for (i = 0; i < 4; i++)
        writeRegister8(i, ISSI_BANK_FUNCTIONREG, ISSI_REG_SHUTDOWN, 0x00);

    wait(0.01);

    for (i = 0; i < 4; i++) {
        writeRegister8(i, ISSI_BANK_FUNCTIONREG, ISSI_REG_SHUTDOWN, 0x01);

        // picture mode
        writeRegister8(i, ISSI_BANK_FUNCTIONREG, ISSI_REG_CONFIG, ISSI_REG_CONFIG_PICTUREMODE);

        displayFrame(i, 0);

        // all LEDs on & 0 PWM
        clear(i); // set each led to 0 PWM

        for (uint8_t f=0; f<8; f++) {
            for (uint8_t j=0; j<=0x11; j++)
                writeRegister8(i, f, j, 0xff);     // each 8 LEDs on
        }

        writeRegister8(i, ISSI_BANK_FUNCTIONREG, ISSI_REG_AUDIOSYNC, 0x0);
    }

    return true;
}

void IS31FL3731::clear(uint8_t driver) {
    selectBank(driver, 0);
  
    uint8_t nemo[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for (uint8_t i=0; i<6; i++) {
        writeBytes(addresses[driver], 0x24+i*24, 24, nemo);
    }
}

void IS31FL3731::setLEDPWM(uint8_t driver, uint8_t lednum, uint8_t pwm, uint8_t bank) {
    if (lednum >= 144) return;
    writeRegister8(driver, bank, 0x24+lednum, pwm);
}

void IS31FL3731::displayFrame(uint8_t driver, uint8_t f) {
    if (f > 7) f = 0;
    writeRegister8(driver, ISSI_BANK_FUNCTIONREG, ISSI_REG_PICTUREFRAME, f);
}


void IS31FL3731::selectBank(uint8_t driver, uint8_t b) {
    writeBytes(addresses[driver], ISSI_COMMANDREGISTER, 1, &b);
}

/*************/
void IS31FL3731::writeRegister8(uint8_t driver, uint8_t b, uint8_t reg, uint8_t data) {
    selectBank(driver, b);
    writeBytes(addresses[driver], reg, 1, &data);
}

void IS31FL3731::writeBytes(uint8_t address, uint8_t reg, uint8_t len, uint8_t *data) {
    i2c.start();
    i2c.write(address << 1);
    i2c.write(reg);
    for (int i = 0; i < len; i++) {
        i2c.write(data[i]);
    }
    i2c.stop();
}
