/*
 * Copyright (c) 2020 Seagate Technology LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Describe the IAP commands interface on NXP LPC11U6x MCUs.
 *
 * The IAP (In-Application Programming) commands are located in the boot ROM
 * code. Mostly they provide access to the on-chip flash and EEPROM devices.
 *
 * @note For details about IAP see the UM10732 LPC11U6x/E6x user manual,
 *       chapter 27: LPC11U6x/E6x Flash/EEPROM ISP/IAP programming.
 */

#ifndef LPC11U3X_IAP_H_
#define LPC11U3X_IAP_H_

#include <mbed.h>

/* Pointer to IAP function. */
#define IAP_LOCATION			                        0x1fff1ff1

/* IAP commands. */
#define IAP_CMD_FLASH_PREP_SEC		                    50
#define IAP_CMD_FLASH_WRITE_SEC		                    51
#define IAP_CMD_FLASH_ERASE_SEC		                    52
#define IAP_CMD_FLASH_BLANK_CHECK_SEC	                53
#define IAP_CMD_READ_PART_ID		                    54
#define IAP_CMD_READ_BOOT_CODE_VER	                    55
#define IAP_CMD_MEM_COMPARE		                        56
#define IAP_CMD_REINVOKE_ISP		                    57
#define IAP_CMD_READ_UID		                        58
#define IAP_CMD_FLASH_ERASE_PAGE	                    59
#define IAP_CMD_EEPROM_WRITE		                    61
#define IAP_CMD_EEPROM_READ		                        62

/* IAP status codes. */
#define IAP_STATUS_CMD_SUCCESS		                    0
#define IAP_STATUS_INVALID_CMD		                    1
#define IAP_STATUS_SRC_ADDR_ERROR	                    2
#define IAP_STATUS_DST_ADDR_ERROR	                    3
#define IAP_STATUS_SRC_ADDR_NOT_MAPPED	                4
#define IAP_STATUS_DST_ADDR_NOT_MAPPED	                5
#define IAP_STATUS_COUNT_ERROR		                    6
#define IAP_STATUS_INVALID_SECTOR	                    7
#define IAP_STATUS_SECTOR_NOT_BLANK	                    8
#define IAP_STATUS_SECTOR_NOT_PREPARED	                9
#define IAP_STATUS_COMPARE_ERROR	                    10
#define IAP_STATUS_BUSY			                        11
#define IAP_STATUS_PARAM_ERROR			                12
#define IAP_STATUS_ADDR_ERROR			                13
#define IAP_STATUS_ADDR_NOT_MAPPED			            14
#define IAP_STATUS_CMD_LOCKED			                15
#define IAP_STATUS_INVALID_CODE			                16
#define IAP_STATUS_INVALID_BAUD_RATE			        17
#define IAP_STATUS_STOP_BIT			                    18
#define IAP_STATUS_CODE_READ_PROTECTION_ENABLED			19

typedef void (*IAP_func)(unsigned int[], unsigned int[]);

class IAP {
public:
    static void invokeIsp() {
        unsigned int cmd[5] = { IAP_CMD_REINVOKE_ISP };
        iap_cmd(cmd);
    }

private:
    static unsigned int iap_cmd(unsigned int cmd[5]) {
        auto iap_entry = (IAP_func)IAP_LOCATION;

        unsigned int status[4];
//        __disable_irq();
        iap_entry(cmd, status);
//        __enable_irq();
        return status[0];
    }
};

#endif /* LPC11U3X_IAP_H_ */
