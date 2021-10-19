// This file is autogenerated, see utils/generate_layout.py

#pragma once

#include <mbed.h>

#define KC_NO 0x0000
#define KC_ROLL_OVER 0x0001
#define KC_POST_FAIL 0x0002
#define KC_UNDEFINED 0x0003
#define KC_A 0x0004
#define KC_B 0x0005
#define KC_C 0x0006
#define KC_D 0x0007
#define KC_E 0x0008
#define KC_F 0x0009
#define KC_G 0x000A
#define KC_H 0x000B
#define KC_I 0x000C
#define KC_J 0x000D
#define KC_K 0x000E
#define KC_L 0x000F
#define KC_M 0x0010
#define KC_N 0x0011
#define KC_O 0x0012
#define KC_P 0x0013
#define KC_R 0x0015
#define KC_S 0x0016
#define KC_T 0x0017
#define KC_U 0x0018
#define KC_V 0x0019
#define KC_W 0x001A
#define KC_X 0x001B
#define KC_Y 0x001C
#define KC_Z 0x001D
#define KC_1 0x001E
#define KC_2 0x001F
#define KC_3 0x0020
#define KC_4 0x0021
#define KC_5 0x0022
#define KC_6 0x0023
#define KC_7 0x0024
#define KC_8 0x0025
#define KC_9 0x0026
#define KC_ENTER 0x0028
#define KC_ESCAPE 0x0029
#define KC_BSPACE 0x002A
#define KC_TAB 0x002B
#define KC_SPACE 0x002C
#define KC_MINUS 0x002D
#define KC_EQUAL 0x002E
#define KC_LBRACKET 0x002F
#define KC_RBRACKET 0x0030
#define KC_BSLASH 0x0031
#define KC_NONUS_HASH 0x0032
#define KC_SCOLON 0x0033
#define KC_QUOTE 0x0034
#define KC_GRAVE 0x0035
#define KC_COMMA 0x0036
#define KC_DOT 0x0037
#define KC_SLASH 0x0038
#define KC_CAPSLOCK 0x0039
#define KC_F1 0x003A
#define KC_F2 0x003B
#define KC_F3 0x003C
#define KC_F4 0x003D
#define KC_F5 0x003E
#define KC_F6 0x003F
#define KC_F7 0x0040
#define KC_F8 0x0041
#define KC_F9 0x0042
#define KC_F10 0x0043
#define KC_F11 0x0044
#define KC_F12 0x0045
#define KC_PSCREEN 0x0046
#define KC_SCROLLLOCK 0x0047
#define KC_PAUSE 0x0048
#define KC_INSERT 0x0049
#define KC_HOME 0x004A
#define KC_PGUP 0x004B
#define KC_PGDOWN 0x004E
#define KC_RIGHT 0x004F
#define KC_LEFT 0x0050
#define KC_DOWN 0x0051
#define KC_UP 0x0052
#define KC_NUMLOCK 0x0053
#define KC_KP_SLASH 0x0054
#define KC_KP_ASTERISK 0x0055
#define KC_KP_MINUS 0x0056
#define KC_KP_PLUS 0x0057
#define KC_KP_ENTER 0x0058
#define KC_KP_1 0x0059
#define KC_KP_2 0x005A
#define KC_KP_3 0x005B
#define KC_KP_4 0x005C
#define KC_KP_5 0x005D
#define KC_KP_6 0x005E
#define KC_KP_7 0x005F
#define KC_KP_8 0x0060
#define KC_KP_9 0x0061
#define KC_KP_0 0x0062
#define KC_KP_DOT 0x0063
#define KC_NONUS_BSLASH 0x0064
#define KC_APPLICATION 0x0065
#define KC_POWER 0x0066
#define KC_KP_EQUAL 0x0067
#define KC_F13 0x0068
#define KC_F14 0x0069
#define KC_F15 0x006A
#define KC_F16 0x006B
#define KC_F17 0x006C
#define KC_F18 0x006D
#define KC_F19 0x006E
#define KC_F20 0x006F
#define KC_F21 0x0070
#define KC_F22 0x0071
#define KC_F23 0x0072
#define KC_F24 0x0073
#define KC_EXECUTE 0x0074
#define KC_HELP 0x0075
#define KC_MENU 0x0076
#define KC_SELECT 0x0077
#define KC_STOP 0x0078
#define KC_AGAIN 0x0079
#define KC_UNDO 0x007A
#define KC_CUT 0x007B
#define KC_COPY 0x007C
#define KC_PASTE 0x007D
#define KC_FIND 0x007E
#define KC__MUTE 0x007F
#define KC__VOLUP 0x0080
#define KC__VOLDOWN 0x0081
#define KC_LOCKING_CAPS 0x0082
#define KC_LOCKING_NUM 0x0083
#define KC_LOCKING_SCROLL 0x0084
#define KC_KP_COMMA 0x0085
#define KC_KP_EQUAL_AS400 0x0086
#define KC_INT1 0x0087
#define KC_INT2 0x0088
#define KC_INT3 0x0089
#define KC_INT4 0x008A
#define KC_INT5 0x008B
#define KC_INT6 0x008C
#define KC_INT7 0x008D
#define KC_INT8 0x008E
#define KC_INT9 0x008F
#define KC_LANG1 0x0090
#define KC_LANG2 0x0091
#define KC_LANG3 0x0092
#define KC_LANG4 0x0093
#define KC_LANG5 0x0094
#define KC_LANG6 0x0095
#define KC_LANG7 0x0096
#define KC_LANG8 0x0097
#define KC_LANG9 0x0098
#define KC_ALT_ERASE 0x0099
#define KC_SYSREQ 0x009A
#define KC_CANCEL 0x009B
#define KC_CLEAR 0x009C
#define KC_PRIOR 0x009D
#define KC_RETURN 0x009E
#define KC_SEPARATOR 0x009F
#define KC_OUT 0x00A0
#define KC_OPER 0x00A1
#define KC_CLEAR_AGAIN 0x00A2
#define KC_CRSEL 0x00A3
#define KC_EXSEL 0x00A4
#define KC_LCTRL 0x00E0
#define KC_LSHIFT 0x00E1
#define KC_LALT 0x00E2
#define KC_LGUI 0x00E3
#define KC_RCTRL 0x00E4
#define KC_RSHIFT 0x00E5
#define KC_RALT 0x00E6
#define KC_RGUI 0x00E7
#define KC_FN 0x00FF
#define KC_AUDIO_MUTE 0x01E2
#define KC_AUDIO_VOL_UP 0x01E9
#define KC_AUDIO_VOL_DOWN 0x01EA
#define KC_MEDIA_NEXT_TRACK 0x01B5
#define KC_MEDIA_PREV_TRACK 0x01B6
#define KC_MEDIA_STOP 0x01B7
#define KC_MEDIA_PLAY_PAUSE 0x01CD
#define KC_LVL1 0x0201
#define KC_LVL2 0x0202
#define KC_LVL3 0x0203
#define KC_BOOTLOADER1 0x0204
#define KC_BOOTLOADER2 0x0205
#define KC_BACKLIGHT_DISABLE 0x0206
#define KC_BACKLIGHT_ENABLE 0x0207
#define KC_BACKLIGHT_BRDOWN 0x0208
#define KC_BACKLIGHT_BRUP 0x0209
#define KC_WIN_LOCK 0x020A

struct matrix_loc_t {
    uint8_t r;
    uint8_t c;
};

struct led_loc_t {
    uint8_t driver;
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

const uint16_t indexToKeycode[2][105] = {
    { 0x0029, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F, 0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0035, 0x001E, 0x001F, 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x002D, 0x002E, 0x002A, 0x0049, 0x004A, 0x004B, 0x0053, 0x0054, 0x0055, 0x0056, 0x002B, 0x0014, 0x001A, 0x0008, 0x0015, 0x0017, 0x001C, 0x0018, 0x000C, 0x0012, 0x0013, 0x002F, 0x0030, 0x0031, 0x004C, 0x004D, 0x004E, 0x005F, 0x0060, 0x0061, 0x0057, 0x0039, 0x0004, 0x0016, 0x0007, 0x0009, 0x000A, 0x000B, 0x000D, 0x000E, 0x000F, 0x0033, 0x0034, 0x0028, 0x005C, 0x005D, 0x005E, 0x00E1, 0x001D, 0x001B, 0x0006, 0x0019, 0x0005, 0x0011, 0x0010, 0x0036, 0x0037, 0x0038, 0x00E5, 0x0052, 0x0059, 0x005A, 0x005B, 0x0058, 0x00E0, 0x00E3, 0x00E2, 0x002C, 0x00E6, 0x00FF, 0x0065, 0x00E4, 0x0050, 0x0051, 0x004F, 0x0062, 0x0063, 0x0000 },
    { 0x0000, 0x01CD, 0x0078, 0x01B6, 0x01B5, 0x01E2, 0x01EA, 0x01E9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0207, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0206, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0205, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0204, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0209, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x020A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0208, 0x0000, 0x0000, 0x0000, 0x0000 },
};

const uint8_t keycodeToIndex[256] = {
    104, 105, 105, 105, 59, 79, 77, 61, 40, 62, 63, 64, 45, 65, 66, 67, 81, 80, 46, 47, 38, 41, 60, 42, 44, 78, 39, 76, 43, 75, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 70, 0, 29, 37, 94, 27, 28, 48, 49, 50, 105, 68, 69, 16, 82, 83, 84, 58, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 30, 31, 32, 51, 52, 53, 101, 99, 100, 86, 33, 34, 35, 36, 57, 90, 87, 88, 89, 71, 72, 73, 54, 55, 56, 102, 103, 105, 97, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 91, 74, 93, 92, 98, 85, 95, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 96
};

const uint8_t matrixToIndex[8][16] = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 105, 29, 32 },
    { 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 30, 31 },
    { 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 105, 51, 52, 53 },
    { 74, 105, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 105, 85, 70, 86 },
    { 91, 92, 93, 105, 105, 105, 94, 105, 105, 105, 95, 96, 97, 98, 99, 100 },
    { 105, 105, 105, 105, 105, 105, 105, 36, 35, 34, 33, 57, 89, 88, 87, 101 },
    { 104, 105, 105, 105, 105, 105, 105, 103, 56, 55, 54, 90, 73, 72, 71, 102 },
};

const led_loc_t indexToLed[105] = {
    { 0x03, 0x88, 0x78, 0x68 }, { 0x03, 0x89, 0x79, 0x69 }, { 0x03, 0x8A, 0x7A, 0x6A }, { 0x03, 0x8B, 0x7B, 0x6B }, { 0x03, 0x8C, 0x7C, 0x6C }, { 0x03, 0x8D, 0x7D, 0x6D }, { 0x03, 0x8E, 0x7E, 0x5D }, { 0x03, 0x8F, 0x6E, 0x5E }, { 0x01, 0x80, 0x70, 0x60 }, { 0x01, 0x81, 0x71, 0x61 }, { 0x01, 0x82, 0x72, 0x62 }, { 0x01, 0x83, 0x73, 0x63 }, { 0x01, 0x84, 0x74, 0x64 }, { 0x01, 0x85, 0x75, 0x65 }, { 0x01, 0x86, 0x76, 0x55 }, { 0x01, 0x87, 0x66, 0x56 }, { 0x03, 0x08, 0x29, 0x39 }, { 0x03, 0x09, 0x19, 0x3A }, { 0x03, 0x0A, 0x1A, 0x2A }, { 0x03, 0x0B, 0x1B, 0x2B }, { 0x03, 0x0C, 0x1C, 0x2C }, { 0x03, 0x0D, 0x1D, 0x2D }, { 0x03, 0x0E, 0x1E, 0x2E }, { 0x03, 0x0F, 0x1F, 0x2F }, { 0x01, 0x00, 0x21, 0x31 }, { 0x01, 0x01, 0x11, 0x32 }, { 0x01, 0x02, 0x12, 0x22 }, { 0x01, 0x03, 0x13, 0x23 }, { 0x01, 0x04, 0x14, 0x24 }, { 0x01, 0x06, 0x16, 0x26 }, { 0x01, 0x07, 0x17, 0x27 }, { 0x02, 0x01, 0x11, 0x32 }, { 0x02, 0x09, 0x19, 0x3A }, { 0x02, 0x0A, 0x1A, 0x2A }, { 0x02, 0x0B, 0x1B, 0x2B }, { 0x02, 0x0C, 0x1C, 0x2C }, { 0x02, 0x0D, 0x1D, 0x2D }, { 0x00, 0x80, 0x70, 0x60 }, { 0x00, 0x81, 0x71, 0x61 }, { 0x00, 0x82, 0x72, 0x62 }, { 0x00, 0x83, 0x73, 0x63 }, { 0x00, 0x84, 0x74, 0x64 }, { 0x00, 0x85, 0x75, 0x65 }, { 0x00, 0x86, 0x76, 0x55 }, { 0x00, 0x87, 0x66, 0x56 }, { 0x01, 0x88, 0x78, 0x68 }, { 0x01, 0x89, 0x79, 0x69 }, { 0x01, 0x8A, 0x7A, 0x6A }, { 0x01, 0x8B, 0x7B, 0x6B }, { 0x01, 0x8C, 0x7C, 0x6C }, { 0x01, 0x8D, 0x7D, 0x6D }, { 0x01, 0x8E, 0x7E, 0x5D }, { 0x01, 0x8F, 0x6E, 0x5E }, { 0x02, 0x08, 0x29, 0x39 }, { 0x02, 0x8E, 0x7E, 0x5D }, { 0x02, 0x8F, 0x6E, 0x5E }, { 0x02, 0x0F, 0x1F, 0x2F }, { 0x02, 0x0E, 0x1E, 0x2E }, { 0x00, 0x00, 0x21, 0x31 }, { 0x00, 0x01, 0x11, 0x32 }, { 0x00, 0x02, 0x12, 0x22 }, { 0x00, 0x03, 0x13, 0x23 }, { 0x00, 0x04, 0x14, 0x24 }, { 0x00, 0x05, 0x15, 0x25 }, { 0x00, 0x06, 0x16, 0x26 }, { 0x00, 0x07, 0x17, 0x27 }, { 0x01, 0x08, 0x29, 0x39 }, { 0x01, 0x09, 0x19, 0x3A }, { 0x01, 0x0A, 0x1A, 0x2A }, { 0x01, 0x0B, 0x1B, 0x2B }, { 0x01, 0x0D, 0x1D, 0x2D }, { 0x02, 0x8B, 0x7B, 0x6B }, { 0x02, 0x8C, 0x7C, 0x6C }, { 0x02, 0x8D, 0x7D, 0x6D }, { 0x00, 0x88, 0x78, 0x68 }, { 0x00, 0x8A, 0x7A, 0x6A }, { 0x00, 0x8B, 0x7B, 0x6B }, { 0x00, 0x8C, 0x7C, 0x6C }, { 0x00, 0x8D, 0x7D, 0x6D }, { 0x00, 0x8E, 0x7E, 0x5D }, { 0x00, 0x8F, 0x6E, 0x5E }, { 0x02, 0x80, 0x70, 0x60 }, { 0x02, 0x81, 0x71, 0x61 }, { 0x02, 0x82, 0x72, 0x62 }, { 0x02, 0x83, 0x73, 0x63 }, { 0x01, 0x0F, 0x1F, 0x2F }, { 0x02, 0x07, 0x17, 0x27 }, { 0x02, 0x88, 0x78, 0x68 }, { 0x02, 0x89, 0x79, 0x69 }, { 0x02, 0x8A, 0x7A, 0x6A }, { 0x02, 0x02, 0x12, 0x22 }, { 0x00, 0x08, 0x29, 0x39 }, { 0x00, 0x09, 0x19, 0x3A }, { 0x00, 0x0A, 0x1A, 0x2A }, { 0x00, 0x0C, 0x1C, 0x2C }, { 0x00, 0x0F, 0x1F, 0x2F }, { 0x02, 0x84, 0x74, 0x64 }, { 0x02, 0x85, 0x75, 0x65 }, { 0x02, 0x86, 0x76, 0x55 }, { 0x02, 0x87, 0x66, 0x56 }, { 0x02, 0x06, 0x16, 0x26 }, { 0x02, 0x05, 0x15, 0x25 }, { 0x02, 0x04, 0x14, 0x24 }, { 0x02, 0x03, 0x13, 0x23 }, { 0x00, 0xFF, 0xFF, 0xFF }
};

const uint8_t keyCount = 104;
