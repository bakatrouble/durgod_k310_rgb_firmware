//
// Created by bakatrouble on 18/10/2021.
//

#include "modules/LEDController.h"
#include "layout.h"

void LEDController::init() {
    i2c.frequency(400000);

    // disable driver
    setDriversPower(false);
    wait(.01);
    // set static picture mode
    setDriversConfig(ISSI_REG_CONFIG_PICTUREMODE);
    // disable audiosync
    setAudioSync(false);
    // clear and select secondary framebuffer
    lowLevelClear(ISSI_SECONDARY_BUFFER);
    display();
    // clear and select primary framebuffer
    lowLevelClear(ISSI_PRIMARY_BUFFER);
    display();
    // enable driver
    setDriversPower(true);
}

void LEDController::display() {
    activeFrame = inactiveFrame();
    writeBuffer(activeFrame);
    callFunction(ISSI_REG_PICTUREFRAME, activeFrame);
}

void LEDController::setKeyColor(uint8_t idx, Color color) {
    if (idx >= keyCount) return;
    auto *ledLoc = &indexToLed[idx];
    ledBuffer[ledLoc->driver][ledLoc->r / 24][ledLoc->r % 24] = color.r;
    ledBuffer[ledLoc->driver][ledLoc->g / 24][ledLoc->g % 24] = color.g;
    ledBuffer[ledLoc->driver][ledLoc->b / 24][ledLoc->b % 24] = color.b;
}

void LEDController::setAllKeys(Color color) {
    for (uint8_t i=0; i < keyCount; i++) {
        setKeyColor(i, color);
    }
}

void LEDController::callFunction(uint8_t functionId, uint8_t arg) {
    for (uint8_t i=0; i < 4; i++) {
        writeRegister8(i, ISSI_BANK_FUNCTIONREG, functionId, arg);
    }
}

void LEDController::setDriversPower(bool enabled) {
    callFunction(ISSI_REG_SHUTDOWN, (uint8_t)enabled);
}

void LEDController::setDriversConfig(uint8_t value) {
    callFunction(ISSI_REG_CONFIG, value);
}

void LEDController::setAudioSync(bool enabled) {
    callFunction(ISSI_REG_AUDIOSYNC, (uint8_t)enabled);
}

void LEDController::selectBank(uint8_t driver, uint8_t bank) {
    writeBytes(driver, ISSI_COMMANDREGISTER, 1, &bank);
}

void LEDController::writeRegister8(uint8_t driver, uint8_t bank, uint8_t reg, uint8_t data) {
    selectBank(driver, bank);
    writeBytes(driver, reg, 1, &data);
}

void LEDController::writeBytes(uint8_t driver, uint8_t reg, uint8_t n, uint8_t *data) {
    i2c.start();
    i2c.write(addresses[driver] << 1);
    i2c.write(reg);
    for (uint8_t i = 0; i < n; i++)
        i2c.write(data[i]);
    i2c.stop();
}

void LEDController::writeBuffer(uint8_t frame) {
    for (uint8_t driver=0; driver < 4; driver++) {
        selectBank(driver, frame);
        for (uint8_t i=0; i < 6; i++) {
            writeBytes(driver, COLOR_OFFSET + i*24, 24, const_cast<uint8_t*>(ledBuffer[driver][i]));
        }
    }
}

void LEDController::lowLevelClear(uint8_t frame) {
    uint8_t enable = 0xFF;

    writeBuffer(frame);
    for (uint8_t driver=0; driver < 4; driver++) {
        selectBank(driver, frame);
        for (uint8_t i=0; i < 18; i++) {
            writeBytes(driver, ENABLE_OFFSET + i, 1, &enable);
        }
    }
}

