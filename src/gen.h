// This file is autogenerated, see generate_layout.py

#pragma once

#define KC_ESC 0x29
#define KC_F1 0x3A
#define KC_F2 0x3B
#define KC_F3 0x3C
#define KC_F4 0x3D
#define KC_F5 0x3E
#define KC_F6 0x3F
#define KC_F7 0x40
#define KC_F8 0x41
#define KC_F9 0x42
#define KC_F10 0x43
#define KC_F11 0x44
#define KC_F12 0x45
#define KC_PSCR 0x46
#define KC_SLCK 0x47
#define KC_PAUS 0x48
#define KC_GRV 0x35
#define KC_1 0x1E
#define KC_2 0x1F
#define KC_3 0x20
#define KC_4 0x21
#define KC_5 0x22
#define KC_6 0x23
#define KC_7 0x24
#define KC_8 0x25
#define KC_9 0x26
#define KC_0 0x27
#define KC_MINS 0x2D
#define KC_EQL 0x2E
#define KC_BSPC 0x2A
#define KC_INS 0x49
#define KC_HOME 0x4A
#define KC_PGUP 0x4B
#define KC_NLCK 0x53
#define KC_PSLS 0x54
#define KC_PAST 0x55
#define KC_PMNS 0x56
#define KC_TAB 0x2B
#define KC_Q 0x14
#define KC_W 0x1A
#define KC_E 0x08
#define KC_R 0x15
#define KC_T 0x17
#define KC_Y 0x1C
#define KC_U 0x18
#define KC_I 0x0C
#define KC_O 0x12
#define KC_P 0x13
#define KC_LBRC 0x2F
#define KC_RBRC 0x30
#define KC_BSLS 0x31
#define KC_DEL 0x4C
#define KC_END 0x4D
#define KC_PGDN 0x4E
#define KC_KP_7 0x5F
#define KC_KP_8 0x60
#define KC_KP_9 0x61
#define KC_PPLS 0x57
#define KC_CAPS 0x39
#define KC_A 0x04
#define KC_S 0x16
#define KC_D 0x07
#define KC_F 0x09
#define KC_G 0x0A
#define KC_H 0x0B
#define KC_J 0x0D
#define KC_K 0x0E
#define KC_L 0x0F
#define KC_SCLN 0x33
#define KC_QUOT 0x34
#define KC_ENT 0x28
#define KC_KP_4 0x5C
#define KC_KP_5 0x5D
#define KC_KP_6 0x5E
#define KC_LSFT 0xE1
#define KC_Z 0x1D
#define KC_X 0x1B
#define KC_C 0x06
#define KC_V 0x19
#define KC_B 0x05
#define KC_N 0x11
#define KC_M 0x10
#define KC_COMM 0x36
#define KC_DOT 0x37
#define KC_SLSH 0x38
#define KC_RSFT 0xE5
#define KC_UP 0x52
#define KC_KP_1 0x59
#define KC_KP_2 0x5A
#define KC_KP_3 0x5B
#define KC_PENT 0x58
#define KC_LCTL 0xE0
#define KC_LGUI 0xE3
#define KC_LALT 0xE2
#define KC_SPC 0x2C
#define KC_RALT 0xE6
#define KC_FN0 0xC0
#define KC_APP 0x65
#define KC_RCTL 0xE4
#define KC_LEFT 0x50
#define KC_DOWN 0x51
#define KC_RGHT 0x4F
#define KC_KP_0 0x62
#define KC_PDOT 0x63
#define KC_NO 0x00

#define KCLASS_GENERIC 0
#define KCLASS_CONSUMER 1

struct matrix_loc_t { uint8_t r; uint8_t c; };

struct led_loc_t { uint8_t driver; uint8_t r; uint8_t g; uint8_t b; };

const uint8_t indexToKeycode[2][105] = {
    { 0x29, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x35, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x2D, 0x2E, 0x2A, 0x49, 0x4A, 0x4B, 0x53, 0x54, 0x55, 0x56, 0x2B, 0x14, 0x1A, 0x08, 0x15, 0x17, 0x1C, 0x18, 0x0C, 0x12, 0x13, 0x2F, 0x30, 0x31, 0x4C, 0x4D, 0x4E, 0x5F, 0x60, 0x61, 0x57, 0x39, 0x04, 0x16, 0x07, 0x09, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F, 0x33, 0x34, 0x28, 0x5C, 0x5D, 0x5E, 0xE1, 0x1D, 0x1B, 0x06, 0x19, 0x05, 0x11, 0x10, 0x36, 0x37, 0x38, 0xE5, 0x52, 0x59, 0x5A, 0x5B, 0x58, 0xE0, 0xE3, 0xE2, 0x2C, 0xE6, 0xC0, 0x65, 0xE4, 0x50, 0x51, 0x4F, 0x62, 0x63, 0x00 },
    { 0x00, 0xCD, 0x78, 0xB6, 0xB5, 0xE2, 0xEA, 0xE9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
};

const uint8_t indexToKeycodeClass[2][105] = {
    { KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC },
    { KCLASS_GENERIC, KCLASS_CONSUMER, KCLASS_CONSUMER, KCLASS_CONSUMER, KCLASS_CONSUMER, KCLASS_CONSUMER, KCLASS_CONSUMER, KCLASS_CONSUMER, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC, KCLASS_GENERIC },
};

const uint8_t keycodeToIndex[256] = {
    104, 105, 105, 105, 59, 79, 77, 61, 40, 62, 63, 64, 45, 65, 66, 67, 81, 80, 46, 47, 38, 41, 60, 42, 44, 78, 39, 76, 43, 75, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 70, 0, 29, 37, 94, 27, 28, 48, 49, 50, 105, 68, 69, 16, 82, 83, 84, 58, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 30, 31, 32, 51, 52, 53, 101, 99, 100, 86, 33, 34, 35, 36, 57, 90, 87, 88, 89, 71, 72, 73, 54, 55, 56, 102, 103, 105, 97, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 96, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 91, 74, 93, 92, 98, 85, 95, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105
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

const matrix_loc_t indexToMatrix[105] = {
    { 0x00, 0x00 }, { 0x00, 0x01 }, { 0x00, 0x02 }, { 0x00, 0x03 }, { 0x00, 0x04 }, { 0x00, 0x05 }, { 0x00, 0x06 }, { 0x00, 0x07 }, { 0x00, 0x08 }, { 0x00, 0x09 }, { 0x00, 0x0A }, { 0x00, 0x0B }, { 0x00, 0x0C }, { 0x00, 0x0D }, { 0x00, 0x0E }, { 0x00, 0x0F }, { 0x01, 0x00 }, { 0x01, 0x01 }, { 0x01, 0x02 }, { 0x01, 0x03 }, { 0x01, 0x04 }, { 0x01, 0x05 }, { 0x01, 0x06 }, { 0x01, 0x07 }, { 0x01, 0x08 }, { 0x01, 0x09 }, { 0x01, 0x0A }, { 0x01, 0x0B }, { 0x01, 0x0C }, { 0x01, 0x0E }, { 0x02, 0x0E }, { 0x02, 0x0F }, { 0x01, 0x0F }, { 0x06, 0x0A }, { 0x06, 0x09 }, { 0x06, 0x08 }, { 0x06, 0x07 }, { 0x02, 0x00 }, { 0x02, 0x01 }, { 0x02, 0x02 }, { 0x02, 0x03 }, { 0x02, 0x04 }, { 0x02, 0x05 }, { 0x02, 0x06 }, { 0x02, 0x07 }, { 0x02, 0x08 }, { 0x02, 0x09 }, { 0x02, 0x0A }, { 0x02, 0x0B }, { 0x02, 0x0C }, { 0x02, 0x0D }, { 0x03, 0x0D }, { 0x03, 0x0E }, { 0x03, 0x0F }, { 0x07, 0x0A }, { 0x07, 0x09 }, { 0x07, 0x08 }, { 0x06, 0x0B }, { 0x03, 0x00 }, { 0x03, 0x01 }, { 0x03, 0x02 }, { 0x03, 0x03 }, { 0x03, 0x04 }, { 0x03, 0x05 }, { 0x03, 0x06 }, { 0x03, 0x07 }, { 0x03, 0x08 }, { 0x03, 0x09 }, { 0x03, 0x0A }, { 0x03, 0x0B }, { 0x04, 0x0E }, { 0x07, 0x0E }, { 0x07, 0x0D }, { 0x07, 0x0C }, { 0x04, 0x00 }, { 0x04, 0x02 }, { 0x04, 0x03 }, { 0x04, 0x04 }, { 0x04, 0x05 }, { 0x04, 0x06 }, { 0x04, 0x07 }, { 0x04, 0x08 }, { 0x04, 0x09 }, { 0x04, 0x0A }, { 0x04, 0x0B }, { 0x04, 0x0D }, { 0x04, 0x0F }, { 0x06, 0x0E }, { 0x06, 0x0D }, { 0x06, 0x0C }, { 0x07, 0x0B }, { 0x05, 0x00 }, { 0x05, 0x01 }, { 0x05, 0x02 }, { 0x05, 0x06 }, { 0x05, 0x0A }, { 0x05, 0x0B }, { 0x05, 0x0C }, { 0x05, 0x0D }, { 0x05, 0x0E }, { 0x05, 0x0F }, { 0x06, 0x0F }, { 0x07, 0x0F }, { 0x07, 0x07 }, { 0x07, 0x00 }
};

const led_loc_t indexToLed[105] = {
    { 0x03, 0x88, 0x78, 0x68 }, { 0x03, 0x89, 0x79, 0x69 }, { 0x03, 0x8A, 0x7A, 0x6A }, { 0x03, 0x8B, 0x7B, 0x6B }, { 0x03, 0x8C, 0x7C, 0x6C }, { 0x03, 0x8D, 0x7D, 0x6D }, { 0x03, 0x8E, 0x7E, 0x5D }, { 0x03, 0x8F, 0x6E, 0x5E }, { 0x01, 0x80, 0x70, 0x60 }, { 0x01, 0x81, 0x71, 0x61 }, { 0x01, 0x82, 0x72, 0x62 }, { 0x01, 0x83, 0x73, 0x63 }, { 0x01, 0x84, 0x74, 0x64 }, { 0x01, 0x85, 0x75, 0x65 }, { 0x01, 0x86, 0x76, 0x55 }, { 0x01, 0x87, 0x66, 0x56 }, { 0x03, 0x08, 0x29, 0x39 }, { 0x03, 0x09, 0x19, 0x3A }, { 0x03, 0x0A, 0x1A, 0x2A }, { 0x03, 0x0B, 0x1B, 0x2B }, { 0x03, 0x0C, 0x1C, 0x2C }, { 0x03, 0x0D, 0x1D, 0x2D }, { 0x03, 0x0E, 0x1E, 0x2E }, { 0x03, 0x0F, 0x1F, 0x2F }, { 0x01, 0x00, 0x21, 0x31 }, { 0x01, 0x01, 0x11, 0x32 }, { 0x01, 0x02, 0x12, 0x22 }, { 0x01, 0x03, 0x13, 0x23 }, { 0x01, 0x04, 0x14, 0x24 }, { 0x01, 0x06, 0x16, 0x26 }, { 0x01, 0x07, 0x17, 0x27 }, { 0x02, 0x01, 0x11, 0x32 }, { 0x02, 0x09, 0x19, 0x3A }, { 0x02, 0x0A, 0x1A, 0x2A }, { 0x02, 0x0B, 0x1B, 0x2B }, { 0x02, 0x0C, 0x1C, 0x2C }, { 0x02, 0x0D, 0x1D, 0x2D }, { 0x00, 0x80, 0x70, 0x60 }, { 0x00, 0x81, 0x71, 0x61 }, { 0x00, 0x82, 0x72, 0x62 }, { 0x00, 0x83, 0x73, 0x63 }, { 0x00, 0x84, 0x74, 0x64 }, { 0x00, 0x85, 0x75, 0x65 }, { 0x00, 0x86, 0x76, 0x55 }, { 0x00, 0x87, 0x66, 0x56 }, { 0x01, 0x88, 0x78, 0x68 }, { 0x01, 0x89, 0x79, 0x69 }, { 0x01, 0x8A, 0x7A, 0x6A }, { 0x01, 0x8B, 0x7B, 0x6B }, { 0x01, 0x8C, 0x7C, 0x6C }, { 0x01, 0x8D, 0x7D, 0x6D }, { 0x01, 0x8E, 0x7E, 0x5D }, { 0x01, 0x8F, 0x6E, 0x5E }, { 0x02, 0x08, 0x29, 0x39 }, { 0x02, 0x8E, 0x7E, 0x5D }, { 0x02, 0x8F, 0x6E, 0x5E }, { 0x02, 0x0F, 0x1F, 0x2F }, { 0x02, 0x0E, 0x1E, 0x2E }, { 0x00, 0x00, 0x21, 0x31 }, { 0x00, 0x01, 0x11, 0x32 }, { 0x00, 0x02, 0x12, 0x22 }, { 0x00, 0x03, 0x13, 0x23 }, { 0x00, 0x04, 0x14, 0x24 }, { 0x00, 0x05, 0x15, 0x25 }, { 0x00, 0x06, 0x16, 0x26 }, { 0x00, 0x07, 0x17, 0x27 }, { 0x01, 0x08, 0x29, 0x39 }, { 0x01, 0x09, 0x19, 0x3A }, { 0x01, 0x0A, 0x1A, 0x2A }, { 0x01, 0x0B, 0x1B, 0x2B }, { 0x01, 0x0D, 0x1D, 0x2D }, { 0x02, 0x8B, 0x7B, 0x6B }, { 0x02, 0x8C, 0x7C, 0x6C }, { 0x02, 0x8D, 0x7D, 0x6D }, { 0x00, 0x88, 0x78, 0x68 }, { 0x00, 0x8A, 0x7A, 0x6A }, { 0x00, 0x8B, 0x7B, 0x6B }, { 0x00, 0x8C, 0x7C, 0x6C }, { 0x00, 0x8D, 0x7D, 0x6D }, { 0x00, 0x8E, 0x7E, 0x5D }, { 0x00, 0x8F, 0x6E, 0x5E }, { 0x02, 0x80, 0x70, 0x60 }, { 0x02, 0x81, 0x71, 0x61 }, { 0x02, 0x82, 0x72, 0x62 }, { 0x02, 0x83, 0x73, 0x63 }, { 0x01, 0x0F, 0x1F, 0x2F }, { 0x02, 0x07, 0x17, 0x27 }, { 0x02, 0x88, 0x78, 0x68 }, { 0x02, 0x89, 0x79, 0x69 }, { 0x02, 0x8A, 0x7A, 0x6A }, { 0x02, 0x02, 0x12, 0x22 }, { 0x00, 0x08, 0x29, 0x39 }, { 0x00, 0x09, 0x19, 0x3A }, { 0x00, 0x0A, 0x1A, 0x2A }, { 0x00, 0x0C, 0x1C, 0x2C }, { 0x00, 0x0F, 0x1F, 0x2F }, { 0x02, 0x84, 0x74, 0x64 }, { 0x02, 0x85, 0x75, 0x65 }, { 0x02, 0x86, 0x76, 0x55 }, { 0x02, 0x87, 0x66, 0x56 }, { 0x02, 0x06, 0x16, 0x26 }, { 0x02, 0x05, 0x15, 0x25 }, { 0x02, 0x04, 0x14, 0x24 }, { 0x02, 0x03, 0x13, 0x23 }, { 0x00, 0xFF, 0xFF, 0xFF }
};

