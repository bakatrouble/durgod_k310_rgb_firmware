//
// Created by bakatrouble on 18/10/2021.
//

#include "LEDController.h"
#include "gen.h"

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
    displayFrame(ISSI_SECONDARY_BUFFER);
    // clear and select primary framebuffer
    lowLevelClear(ISSI_PRIMARY_BUFFER);
    displayFrame(ISSI_PRIMARY_BUFFER);
    // enable driver
    setDriversPower(true);
}

uint8_t LEDController::toggleFrame() {
    displayFrame(inactiveFrame());
    return activeFrame;
}

void LEDController::displayFrame(uint8_t frame) {
    if (frame > 7) frame = 0;
    activeFrame = frame;
    callFunction(ISSI_REG_PICTUREFRAME, frame);
}

void LEDController::setKeyColor(uint8_t idx, Color color, bool inBuffer) {
    if (idx >= keyCount) return;
    auto *ledLoc = &indexToLed[idx];
    writeRegister8(ledLoc->driver, inBuffer ? inactiveFrame() : activeFrame, COLOR_OFFSET + ledLoc->r, color.r);
    writeRegister8(ledLoc->driver, inBuffer ? inactiveFrame() : activeFrame, COLOR_OFFSET + ledLoc->g, color.g);
    writeRegister8(ledLoc->driver, inBuffer ? inactiveFrame() : activeFrame, COLOR_OFFSET + ledLoc->b, color.b);
}

void LEDController::setAllKeys(Color color, bool inBuffer) {
    for (uint8_t i=0; i < keyCount; i++) {
        setKeyColor(i, color, inBuffer);
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

void LEDController::lowLevelClear(uint8_t frame) {
    uint8_t nemo[24] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    uint8_t enable = 0xFF;

    for (uint8_t driver=0; driver < 4; driver++) {
        selectBank(driver, frame);
        for (uint8_t i=0; i < 6; i++) {
            writeBytes(driver, COLOR_OFFSET + i*24, 24, nemo);
        }
        for (uint8_t i=0; i < 18; i++) {
            writeBytes(driver, ENABLE_OFFSET + i, 1, &enable);
        }
    }
}

