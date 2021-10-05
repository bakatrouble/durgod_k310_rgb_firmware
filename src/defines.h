#ifndef MBED_PLATFORMIO_DEFINES_H
#define MBED_PLATFORMIO_DEFINES_H

#define LED_NUMLOCK_PIN P1_9
#define LED_CAPSLOCK_PIN P0_23
#define LED_SCROLLLOCK_PIN P1_15
#define LED_WINLOCK_PIN P1_13
#define LED_APP_PIN P1_11

//#define IAP_LOCATION 0x1fff1ff1
//typedef void (*IAP)(unsigned int[], unsigned int[]);
//IAP iap_entry = (IAP)IAP_LOCATION;

#define MATRIX_ROW_PINS { P0_7, P0_8, P0_9, P0_22, P0_11, P0_12, P0_13, P0_14 }
#define MATRIX_COL_PINS { P1_12, P0_17, P0_18, P0_19, P1_16, P1_6, P1_0, P1_25, P1_19, P1_10, P0_2, P1_26, P1_27, P1_4, P1_1, P1_20 }

const PinName colPins[] = MATRIX_COL_PINS;
const PinName rowPins[] = MATRIX_ROW_PINS;


#endif //MBED_PLATFORMIO_DEFINES_H
