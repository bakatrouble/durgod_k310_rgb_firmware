import enum
from dataclasses import dataclass
from typing import Iterable

from mako.template import Template

KC_NO = 0x00
KC_ROLL_OVER = 0x01
KC_POST_FAIL = 0x02
KC_UNDEFINED = 0x03
KC_A = 0x04
KC_B = 0x05
KC_C = 0x06
KC_D = 0x07
KC_E = 0x08
KC_F = 0x09
KC_G = 0x0A
KC_H = 0x0B
KC_I = 0x0C
KC_J = 0x0D
KC_K = 0x0E
KC_L = 0x0F
KC_M = 0x10
KC_N = 0x11
KC_O = 0x12
KC_P = 0x13
KC_Q = 0x14
KC_R = 0x15
KC_S = 0x16
KC_T = 0x17
KC_U = 0x18
KC_V = 0x19
KC_W = 0x1A
KC_X = 0x1B
KC_Y = 0x1C
KC_Z = 0x1D
KC_1 = 0x1E
KC_2 = 0x1F
KC_3 = 0x20
KC_4 = 0x21
KC_5 = 0x22
KC_6 = 0x23
KC_7 = 0x24
KC_8 = 0x25
KC_9 = 0x26
KC_0 = 0x27
KC_ENTER = KC_ENT = 0x28
KC_ESCAPE = KC_ESC = 0x29
KC_BSPACE = KC_BSPC = 0x2A
KC_TAB = 0x2B
KC_SPACE = KC_SPC = 0x2C
KC_MINUS = KC_MINS = 0x2D
KC_EQUAL = KC_EQL = 0x2E
KC_LBRACKET = KC_LBRC = 0x2F
KC_RBRACKET = KC_RBRC = 0x30
KC_BSLASH = KC_BSLS = 0x31
KC_NONUS_HASH = 0x32
KC_SCOLON = KC_SCLN = 0x33
KC_QUOTE = KC_QUOT = 0x34
KC_GRAVE = KC_GRV = 0x35
KC_COMMA = KC_COMM = 0x36
KC_DOT = 0x37
KC_SLASH = KC_SLSH = 0x38
KC_CAPSLOCK = KC_CAPS = 0x39
KC_F1 = 0x3A
KC_F2 = 0x3B
KC_F3 = 0x3C
KC_F4 = 0x3D
KC_F5 = 0x3E
KC_F6 = 0x3F
KC_F7 = 0x40
KC_F8 = 0x41
KC_F9 = 0x42
KC_F10 = 0x43
KC_F11 = 0x44
KC_F12 = 0x45
KC_PSCREEN = KC_PSCR = 0x46
KC_SCROLLLOCK = KC_SLCK = 0x47
KC_PAUSE = KC_PAUS = 0x48
KC_INSERT = KC_INS = 0x49
KC_HOME = 0x4A
KC_PGUP = 0x4B
KC_DELETE = KC_DEL = 0x4C
KC_END = 0x4D
KC_PGDOWN = KC_PGDN = 0x4E
KC_RIGHT = KC_RGHT = 0x4F
KC_LEFT = 0x50
KC_DOWN = 0x51
KC_UP = 0x52
KC_NUMLOCK = KC_NLCK = 0x53
KC_KP_SLASH = KC_PSLS = 0x54
KC_KP_ASTERISK = KC_PAST = 0x55
KC_KP_MINUS = KC_PMNS = 0x56
KC_KP_PLUS = KC_PPLS = 0x57
KC_KP_ENTER = KC_PENT = 0x58
KC_KP_1 = 0x59
KC_KP_2 = 0x5A
KC_KP_3 = 0x5B
KC_KP_4 = 0x5C
KC_KP_5 = 0x5D
KC_KP_6 = 0x5E
KC_KP_7 = 0x5F
KC_KP_8 = 0x60
KC_KP_9 = 0x61
KC_KP_0 = 0x62
KC_KP_DOT = KC_PDOT = 0x63
KC_NONUS_BSLASH = 0x64
KC_APPLICATION = KC_APP = 0x65
KC_POWER = 0x66
KC_KP_EQUAL = 0x67
KC_F13 = 0x68
KC_F14 = 0x69
KC_F15 = 0x6A
KC_F16 = 0x6B
KC_F17 = 0x6C
KC_F18 = 0x6D
KC_F19 = 0x6E
KC_F20 = 0x6F
KC_F21 = 0x70
KC_F22 = 0x71
KC_F23 = 0x72
KC_F24 = 0x73
KC_EXECUTE = 0x74
KC_HELP = 0x75
KC_MENU = 0x76
KC_SELECT = 0x77
KC_STOP = 0x78
KC_AGAIN = 0x79
KC_UNDO = 0x7A
KC_CUT = 0x7B
KC_COPY = 0x7C
KC_PASTE = 0x7D
KC_FIND = 0x7E
KC__MUTE = 0x7F
KC__VOLUP = 0x80
KC__VOLDOWN = 0x81
KC_LOCKING_CAPS = 0x82
KC_LOCKING_NUM = 0x83
KC_LOCKING_SCROLL = 0x84
KC_KP_COMMA = 0x85
KC_KP_EQUAL_AS400 = 0x86
KC_INT1 = 0x87
KC_INT2 = 0x88
KC_INT3 = 0x89
KC_INT4 = 0x8A
KC_INT5 = 0x8B
KC_INT6 = 0x8C
KC_INT7 = 0x8D
KC_INT8 = 0x8E
KC_INT9 = 0x8F
KC_LANG1 = 0x90
KC_LANG2 = 0x91
KC_LANG3 = 0x92
KC_LANG4 = 0x93
KC_LANG5 = 0x94
KC_LANG6 = 0x95
KC_LANG7 = 0x96
KC_LANG8 = 0x97
KC_LANG9 = 0x98
KC_ALT_ERASE = 0x99
KC_SYSREQ = 0x9A
KC_CANCEL = 0x9B
KC_CLEAR = 0x9C
KC_PRIOR = 0x9D
KC_RETURN = 0x9E
KC_SEPARATOR = 0x9F
KC_OUT =  0xA0
KC_OPER = 0xA1
KC_CLEAR_AGAIN = 0xA2
KC_CRSEL = 0xA3
KC_EXSEL = 0xA4

KC_LCTRL = KC_LCTL = 0xE0
KC_LSHIFT = KC_LSFT = 0xE1
KC_LALT = 0xE2
KC_LGUI = 0xE3
KC_RCTRL = KC_RCTL = 0xE4
KC_RSHIFT = KC_RSFT = 0xE5
KC_RALT = 0xE6
KC_RGUI = 0xE7

# for layout representation
KC_FN = 0xFF

# consumer
KC_AUDIO_MUTE = 0x1E2
KC_AUDIO_VOL_UP = 0x1E9
KC_AUDIO_VOL_DOWN = 0x1EA
KC_MEDIA_NEXT_TRACK = 0x1B5
KC_MEDIA_PREV_TRACK = 0x1B6
KC_MEDIA_STOP = 0x1B7
KC_MEDIA_PLAY_PAUSE = 0x1CD

# custom
KC_LVL1 = 0x201
KC_LVL2 = 0x202
KC_LVL3 = 0x203
KC_BOOTLOADER1 = 0x204
KC_BOOTLOADER2 = 0x205
KC_BACKLIGHT_DISABLE = 0x206
KC_BACKLIGHT_ENABLE = 0x207
KC_BACKLIGHT_BRDOWN = 0x208
KC_BACKLIGHT_BRUP = 0x209
KC_WIN_LOCK = 0x20A


all_keycodes = {
    'KC_NO': KC_NO,
    'KC_ROLL_OVER': KC_ROLL_OVER,
    'KC_POST_FAIL': KC_POST_FAIL,
    'KC_UNDEFINED': KC_UNDEFINED,
    'KC_A': KC_A,
    'KC_B': KC_B,
    'KC_C': KC_C,
    'KC_D': KC_D,
    'KC_E': KC_E,
    'KC_F': KC_F,
    'KC_G': KC_G,
    'KC_H': KC_H,
    'KC_I': KC_I,
    'KC_J': KC_J,
    'KC_K': KC_K,
    'KC_L': KC_L,
    'KC_M': KC_M,
    'KC_N': KC_N,
    'KC_O': KC_O,
    'KC_P': KC_P,
    'KC_R': KC_R,
    'KC_S': KC_S,
    'KC_T': KC_T,
    'KC_U': KC_U,
    'KC_V': KC_V,
    'KC_W': KC_W,
    'KC_X': KC_X,
    'KC_Y': KC_Y,
    'KC_Z': KC_Z,
    'KC_1': KC_1,
    'KC_2': KC_2,
    'KC_3': KC_3,
    'KC_4': KC_4,
    'KC_5': KC_5,
    'KC_6': KC_6,
    'KC_7': KC_7,
    'KC_8': KC_8,
    'KC_9': KC_9,
    'KC_ENTER': KC_ENTER,
    'KC_ESCAPE': KC_ESCAPE,
    'KC_BSPACE': KC_BSPACE,
    'KC_TAB': KC_TAB,
    'KC_SPACE': KC_SPACE,
    'KC_MINUS': KC_MINUS,
    'KC_EQUAL': KC_EQUAL,
    'KC_LBRACKET': KC_LBRACKET,
    'KC_RBRACKET': KC_RBRACKET,
    'KC_BSLASH': KC_BSLASH,
    'KC_NONUS_HASH': KC_NONUS_HASH,
    'KC_SCOLON': KC_SCOLON,
    'KC_QUOTE': KC_QUOTE,
    'KC_GRAVE': KC_GRAVE,
    'KC_COMMA': KC_COMMA,
    'KC_DOT': KC_DOT,
    'KC_SLASH': KC_SLASH,
    'KC_CAPSLOCK': KC_CAPSLOCK,
    'KC_F1': KC_F1,
    'KC_F2': KC_F2,
    'KC_F3': KC_F3,
    'KC_F4': KC_F4,
    'KC_F5': KC_F5,
    'KC_F6': KC_F6,
    'KC_F7': KC_F7,
    'KC_F8': KC_F8,
    'KC_F9': KC_F9,
    'KC_F10': KC_F10,
    'KC_F11': KC_F11,
    'KC_F12': KC_F12,
    'KC_PSCREEN': KC_PSCREEN,
    'KC_SCROLLLOCK': KC_SCROLLLOCK,
    'KC_PAUSE': KC_PAUSE,
    'KC_INSERT': KC_INSERT,
    'KC_HOME': KC_HOME,
    'KC_PGUP': KC_PGUP,
    'KC_PGDOWN': KC_PGDOWN,
    'KC_RIGHT': KC_RIGHT,
    'KC_LEFT': KC_LEFT,
    'KC_DOWN': KC_DOWN,
    'KC_UP': KC_UP,
    'KC_NUMLOCK': KC_NUMLOCK,
    'KC_KP_SLASH': KC_KP_SLASH,
    'KC_KP_ASTERISK': KC_KP_ASTERISK,
    'KC_KP_MINUS': KC_KP_MINUS,
    'KC_KP_PLUS': KC_KP_PLUS,
    'KC_KP_ENTER': KC_KP_ENTER,
    'KC_KP_1': KC_KP_1,
    'KC_KP_2': KC_KP_2,
    'KC_KP_3': KC_KP_3,
    'KC_KP_4': KC_KP_4,
    'KC_KP_5': KC_KP_5,
    'KC_KP_6': KC_KP_6,
    'KC_KP_7': KC_KP_7,
    'KC_KP_8': KC_KP_8,
    'KC_KP_9': KC_KP_9,
    'KC_KP_0': KC_KP_0,
    'KC_KP_DOT': KC_KP_DOT,
    'KC_NONUS_BSLASH': KC_NONUS_BSLASH,
    'KC_APPLICATION': KC_APPLICATION,
    'KC_POWER': KC_POWER,
    'KC_KP_EQUAL': KC_KP_EQUAL,
    'KC_F13': KC_F13,
    'KC_F14': KC_F14,
    'KC_F15': KC_F15,
    'KC_F16': KC_F16,
    'KC_F17': KC_F17,
    'KC_F18': KC_F18,
    'KC_F19': KC_F19,
    'KC_F20': KC_F20,
    'KC_F21': KC_F21,
    'KC_F22': KC_F22,
    'KC_F23': KC_F23,
    'KC_F24': KC_F24,
    'KC_EXECUTE': KC_EXECUTE,
    'KC_HELP': KC_HELP,
    'KC_MENU': KC_MENU,
    'KC_SELECT': KC_SELECT,
    'KC_STOP': KC_STOP,
    'KC_AGAIN': KC_AGAIN,
    'KC_UNDO': KC_UNDO,
    'KC_CUT': KC_CUT,
    'KC_COPY': KC_COPY,
    'KC_PASTE': KC_PASTE,
    'KC_FIND': KC_FIND,
    'KC__MUTE': KC__MUTE,
    'KC__VOLUP': KC__VOLUP,
    'KC__VOLDOWN': KC__VOLDOWN,
    'KC_LOCKING_CAPS': KC_LOCKING_CAPS,
    'KC_LOCKING_NUM': KC_LOCKING_NUM,
    'KC_LOCKING_SCROLL': KC_LOCKING_SCROLL,
    'KC_KP_COMMA': KC_KP_COMMA,
    'KC_KP_EQUAL_AS400': KC_KP_EQUAL_AS400,
    'KC_INT1': KC_INT1,
    'KC_INT2': KC_INT2,
    'KC_INT3': KC_INT3,
    'KC_INT4': KC_INT4,
    'KC_INT5': KC_INT5,
    'KC_INT6': KC_INT6,
    'KC_INT7': KC_INT7,
    'KC_INT8': KC_INT8,
    'KC_INT9': KC_INT9,
    'KC_LANG1': KC_LANG1,
    'KC_LANG2': KC_LANG2,
    'KC_LANG3': KC_LANG3,
    'KC_LANG4': KC_LANG4,
    'KC_LANG5': KC_LANG5,
    'KC_LANG6': KC_LANG6,
    'KC_LANG7': KC_LANG7,
    'KC_LANG8': KC_LANG8,
    'KC_LANG9': KC_LANG9,
    'KC_ALT_ERASE': KC_ALT_ERASE,
    'KC_SYSREQ': KC_SYSREQ,
    'KC_CANCEL': KC_CANCEL,
    'KC_CLEAR': KC_CLEAR,
    'KC_PRIOR': KC_PRIOR,
    'KC_RETURN': KC_RETURN,
    'KC_SEPARATOR': KC_SEPARATOR,
    'KC_OUT': KC_OUT,
    'KC_OPER': KC_OPER,
    'KC_CLEAR_AGAIN': KC_CLEAR_AGAIN,
    'KC_CRSEL': KC_CRSEL,
    'KC_EXSEL': KC_EXSEL,
    'KC_LCTRL': KC_LCTRL,
    'KC_LSHIFT': KC_LSHIFT,
    'KC_LALT': KC_LALT,
    'KC_LGUI': KC_LGUI,
    'KC_RCTRL': KC_RCTRL,
    'KC_RSHIFT': KC_RSHIFT,
    'KC_RALT': KC_RALT,
    'KC_RGUI': KC_RGUI,
    'KC_FN': KC_FN,
    'KC_AUDIO_MUTE': KC_AUDIO_MUTE,
    'KC_AUDIO_VOL_UP': KC_AUDIO_VOL_UP,
    'KC_AUDIO_VOL_DOWN': KC_AUDIO_VOL_DOWN,
    'KC_MEDIA_NEXT_TRACK': KC_MEDIA_NEXT_TRACK,
    'KC_MEDIA_PREV_TRACK': KC_MEDIA_PREV_TRACK,
    'KC_MEDIA_STOP': KC_MEDIA_STOP,
    'KC_MEDIA_PLAY_PAUSE': KC_MEDIA_PLAY_PAUSE,
    'KC_LVL1': KC_LVL1,
    'KC_LVL2': KC_LVL2,
    'KC_LVL3': KC_LVL3,
    'KC_BOOTLOADER1': KC_BOOTLOADER1,
    'KC_BOOTLOADER2': KC_BOOTLOADER2,
    'KC_BACKLIGHT_DISABLE': KC_BACKLIGHT_DISABLE,
    'KC_BACKLIGHT_ENABLE': KC_BACKLIGHT_ENABLE,
    'KC_BACKLIGHT_BRDOWN': KC_BACKLIGHT_BRDOWN,
    'KC_BACKLIGHT_BRUP': KC_BACKLIGHT_BRUP,
    'KC_WIN_LOCK': KC_WIN_LOCK,
}

key_map = [
    KC_ESC,           KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,      KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN,      KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                       KC_KP_4, KC_KP_5, KC_KP_6,
    KC_LSFT,          KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                 KC_UP,               KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT,
    KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                       KC_RALT, KC_FN,   KC_APP,  KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT,      KC_KP_0,          KC_PDOT
]


@dataclass 
class LedLocation:
    d: int
    r: int
    g: int
    b: int


@dataclass
class MatrixLocation:
    r: int
    c: int


@dataclass
class KeyInfo:
    keycode_name: str
    led_location: LedLocation
    matrix_location: MatrixLocation
    additional_layers: Iterable[int]


LL = LedLocation
ML = MatrixLocation
KI = KeyInfo

key_info = {
    KC_ESC:  KI('KC_ESC',  LL(3, 0x88, 0x78, 0x68), ML(0, 0x0), ()),
    KC_F1:   KI('KC_F1',   LL(3, 0x89, 0x79, 0x69), ML(0, 0x1), (KC_MEDIA_PLAY_PAUSE,)),
    KC_F2:   KI('KC_F2',   LL(3, 0x8A, 0x7A, 0x6A), ML(0, 0x2), (KC_STOP,)),
    KC_F3:   KI('KC_F3',   LL(3, 0x8B, 0x7B, 0x6B), ML(0, 0x3), (KC_MEDIA_PREV_TRACK,)),
    KC_F4:   KI('KC_F4',   LL(3, 0x8C, 0x7C, 0x6C), ML(0, 0x4), (KC_MEDIA_NEXT_TRACK,)),
    KC_F5:   KI('KC_F5',   LL(3, 0x8D, 0x7D, 0x6D), ML(0, 0x5), (KC_AUDIO_MUTE,)),
    KC_F6:   KI('KC_F6',   LL(3, 0x8E, 0x7E, 0x5D), ML(0, 0x6), (KC_AUDIO_VOL_DOWN,)),
    KC_F7:   KI('KC_F7',   LL(3, 0x8F, 0x6E, 0x5E), ML(0, 0x7), (KC_AUDIO_VOL_UP,)),
    KC_F8:   KI('KC_F8',   LL(1, 0x80, 0x70, 0x60), ML(0, 0x8), ()),
    KC_F9:   KI('KC_F9',   LL(1, 0x81, 0x71, 0x61), ML(0, 0x9), ()),
    KC_F10:  KI('KC_F10',  LL(1, 0x82, 0x72, 0x62), ML(0, 0xA), ()),
    KC_F11:  KI('KC_F11',  LL(1, 0x83, 0x73, 0x63), ML(0, 0xB), ()),
    KC_F12:  KI('KC_F12',  LL(1, 0x84, 0x74, 0x64), ML(0, 0xC), ()),
    KC_PSCR: KI('KC_PSCR', LL(1, 0x85, 0x75, 0x65), ML(0, 0xD), ()),
    KC_SLCK: KI('KC_SLCK', LL(1, 0x86, 0x76, 0x55), ML(0, 0xE), ()),
    KC_PAUS: KI('KC_PAUS', LL(1, 0x87, 0x66, 0x56), ML(0, 0xF), ()),

    KC_GRV:  KI('KC_GRV',  LL(3, 0x08, 0x29, 0x39), ML(1, 0x0), ()),
    KC_1:    KI('KC_1',    LL(3, 0x09, 0x19, 0x3A), ML(1, 0x1), ()),
    KC_2:    KI('KC_2',    LL(3, 0x0A, 0x1A, 0x2A), ML(1, 0x2), ()),
    KC_3:    KI('KC_3',    LL(3, 0x0B, 0x1B, 0x2B), ML(1, 0x3), ()),
    KC_4:    KI('KC_4',    LL(3, 0x0C, 0x1C, 0x2C), ML(1, 0x4), ()),
    KC_5:    KI('KC_5',    LL(3, 0x0D, 0x1D, 0x2D), ML(1, 0x5), ()),
    KC_6:    KI('KC_6',    LL(3, 0x0E, 0x1E, 0x2E), ML(1, 0x6), ()),
    KC_7:    KI('KC_7',    LL(3, 0x0F, 0x1F, 0x2F), ML(1, 0x7), ()),
    KC_8:    KI('KC_8',    LL(1, 0x00, 0x21, 0x31), ML(1, 0x8), ()),
    KC_9:    KI('KC_9',    LL(1, 0x01, 0x11, 0x32), ML(1, 0x9), ()),
    KC_0:    KI('KC_0',    LL(1, 0x02, 0x12, 0x22), ML(1, 0xA), ()),
    KC_MINS: KI('KC_MINS', LL(1, 0x03, 0x13, 0x23), ML(1, 0xB), ()),
    KC_EQL:  KI('KC_EQL',  LL(1, 0x04, 0x14, 0x24), ML(1, 0xC), ()),
    KC_BSPC: KI('KC_BSPC', LL(1, 0x06, 0x16, 0x26), ML(1, 0xE), ()),
    KC_INS:  KI('KC_INS',  LL(1, 0x07, 0x17, 0x27), ML(2, 0xE), (KC_BACKLIGHT_ENABLE,)),
    KC_HOME: KI('KC_HOME', LL(2, 0x01, 0x11, 0x32), ML(2, 0xF), ()),
    KC_PGUP: KI('KC_PGUP', LL(2, 0x09, 0x19, 0x3A), ML(1, 0xF), ()),
    KC_NLCK: KI('KC_NLCK', LL(2, 0x0A, 0x1A, 0x2A), ML(6, 0xA), ()),
    KC_PSLS: KI('KC_PSLS', LL(2, 0x0B, 0x1B, 0x2B), ML(6, 0x9), ()),
    KC_PAST: KI('KC_PAST', LL(2, 0x0C, 0x1C, 0x2C), ML(6, 0x8), ()),
    KC_PMNS: KI('KC_PMNS', LL(2, 0x0D, 0x1D, 0x2D), ML(6, 0x7), ()),

    KC_TAB:  KI('KC_TAB',  LL(0, 0x80, 0x70, 0x60), ML(2, 0x0), ()),
    KC_Q:    KI('KC_Q',    LL(0, 0x81, 0x71, 0x61), ML(2, 0x1), ()),
    KC_W:    KI('KC_W',    LL(0, 0x82, 0x72, 0x62), ML(2, 0x2), ()),
    KC_E:    KI('KC_E',    LL(0, 0x83, 0x73, 0x63), ML(2, 0x3), ()),
    KC_R:    KI('KC_R',    LL(0, 0x84, 0x74, 0x64), ML(2, 0x4), ()),
    KC_T:    KI('KC_T',    LL(0, 0x85, 0x75, 0x65), ML(2, 0x5), ()),
    KC_Y:    KI('KC_Y',    LL(0, 0x86, 0x76, 0x55), ML(2, 0x6), ()),
    KC_U:    KI('KC_U',    LL(0, 0x87, 0x66, 0x56), ML(2, 0x7), ()),
    KC_I:    KI('KC_I',    LL(1, 0x88, 0x78, 0x68), ML(2, 0x8), ()),
    KC_O:    KI('KC_O',    LL(1, 0x89, 0x79, 0x69), ML(2, 0x9), ()),
    KC_P:    KI('KC_P',    LL(1, 0x8A, 0x7A, 0x6A), ML(2, 0xA), ()),
    KC_LBRC: KI('KC_LBRC', LL(1, 0x8B, 0x7B, 0x6B), ML(2, 0xB), ()),
    KC_RBRC: KI('KC_RBRC', LL(1, 0x8C, 0x7C, 0x6C), ML(2, 0xC), ()),
    KC_BSLS: KI('KC_BSLS', LL(1, 0x8D, 0x7D, 0x6D), ML(2, 0xD), ()),
    KC_DEL:  KI('KC_DEL',  LL(1, 0x8E, 0x7E, 0x5D), ML(3, 0xD), (KC_BACKLIGHT_DISABLE,)),
    KC_END:  KI('KC_END',  LL(1, 0x8F, 0x6E, 0x5E), ML(3, 0xE), ()),
    KC_PGDN: KI('KC_PGDN', LL(2, 0x08, 0x29, 0x39), ML(3, 0xF), ()),
    KC_KP_7: KI('KC_KP_7', LL(2, 0x8E, 0x7E, 0x5D), ML(7, 0xA), ()),
    KC_KP_8: KI('KC_KP_8', LL(2, 0x8F, 0x6E, 0x5E), ML(7, 0x9), ()),
    KC_KP_9: KI('KC_KP_9', LL(2, 0x0F, 0x1F, 0x2F), ML(7, 0x8), ()),
    KC_PPLS: KI('KC_PPLS', LL(2, 0x0E, 0x1E, 0x2E), ML(6, 0xB), ()),

    KC_CAPS: KI('KC_CAPS', LL(0, 0x00, 0x21, 0x31), ML(3, 0x0), ()),  
    KC_A:    KI('KC_A',    LL(0, 0x01, 0x11, 0x32), ML(3, 0x1), ()),
    KC_S:    KI('KC_S',    LL(0, 0x02, 0x12, 0x22), ML(3, 0x2), ()),
    KC_D:    KI('KC_D',    LL(0, 0x03, 0x13, 0x23), ML(3, 0x3), ()),
    KC_F:    KI('KC_F',    LL(0, 0x04, 0x14, 0x24), ML(3, 0x4), ()),
    KC_G:    KI('KC_G',    LL(0, 0x05, 0x15, 0x25), ML(3, 0x5), ()),
    KC_H:    KI('KC_H',    LL(0, 0x06, 0x16, 0x26), ML(3, 0x6), ()),
    KC_J:    KI('KC_J',    LL(0, 0x07, 0x17, 0x27), ML(3, 0x7), ()),
    KC_K:    KI('KC_K',    LL(1, 0x08, 0x29, 0x39), ML(3, 0x8), ()),
    KC_L:    KI('KC_L',    LL(1, 0x09, 0x19, 0x3A), ML(3, 0x9), (KC_BOOTLOADER2,)),
    KC_SCLN: KI('KC_SCLN', LL(1, 0x0A, 0x1A, 0x2A), ML(3, 0xA), ()),
    KC_QUOT: KI('KC_QUOT', LL(1, 0x0B, 0x1B, 0x2B), ML(3, 0xB), ()),
    KC_ENT:  KI('KC_ENT',  LL(1, 0x0D, 0x1D, 0x2D), ML(4, 0xE), ()),
    KC_KP_4: KI('KC_KP_4', LL(2, 0x8B, 0x7B, 0x6B), ML(7, 0xE), ()),
    KC_KP_5: KI('KC_KP_5', LL(2, 0x8C, 0x7C, 0x6C), ML(7, 0xD), ()),
    KC_KP_6: KI('KC_KP_6', LL(2, 0x8D, 0x7D, 0x6D), ML(7, 0xC), ()),

    KC_LSFT: KI('KC_LSFT', LL(0, 0x88, 0x78, 0x68), ML(4, 0x0), ()),  
    KC_Z:    KI('KC_Z',    LL(0, 0x8A, 0x7A, 0x6A), ML(4, 0x2), ()),
    KC_X:    KI('KC_X',    LL(0, 0x8B, 0x7B, 0x6B), ML(4, 0x3), ()),
    KC_C:    KI('KC_C',    LL(0, 0x8C, 0x7C, 0x6C), ML(4, 0x4), ()),
    KC_V:    KI('KC_V',    LL(0, 0x8D, 0x7D, 0x6D), ML(4, 0x5), ()),
    KC_B:    KI('KC_B',    LL(0, 0x8E, 0x7E, 0x5D), ML(4, 0x6), (KC_BOOTLOADER1,)),
    KC_N:    KI('KC_N',    LL(0, 0x8F, 0x6E, 0x5E), ML(4, 0x7), ()),
    KC_M:    KI('KC_M',    LL(2, 0x80, 0x70, 0x60), ML(4, 0x8), ()),
    KC_COMM: KI('KC_COMM', LL(2, 0x81, 0x71, 0x61), ML(4, 0x9), ()),
    KC_DOT:  KI('KC_DOT',  LL(2, 0x82, 0x72, 0x62), ML(4, 0xA), ()),
    KC_SLSH: KI('KC_SLSH', LL(2, 0x83, 0x73, 0x63), ML(4, 0xB), ()),
    KC_RSFT: KI('KC_RSFT', LL(1, 0x0F, 0x1F, 0x2F), ML(4, 0xD), ()),
    KC_UP:   KI('KC_UP',   LL(2, 0x07, 0x17, 0x27), ML(4, 0xF), (KC_BACKLIGHT_BRUP,)),
    KC_KP_1: KI('KC_KP_1', LL(2, 0x88, 0x78, 0x68), ML(6, 0xE), ()),
    KC_KP_2: KI('KC_KP_2', LL(2, 0x89, 0x79, 0x69), ML(6, 0xD), ()),
    KC_KP_3: KI('KC_KP_3', LL(2, 0x8A, 0x7A, 0x6A), ML(6, 0xC), ()),
    KC_PENT: KI('KC_PENT', LL(2, 0x02, 0x12, 0x22), ML(7, 0xB), ()),

    KC_LCTL: KI('KC_LCTL', LL(0, 0x08, 0x29, 0x39), ML(5, 0x0), ()),  
    KC_LGUI: KI('KC_LGUI', LL(0, 0x09, 0x19, 0x3A), ML(5, 0x1), (KC_WIN_LOCK,)),
    KC_LALT: KI('KC_LALT', LL(0, 0x0A, 0x1A, 0x2A), ML(5, 0x2), ()),
    KC_SPC:  KI('KC_SPC',  LL(0, 0x0C, 0x1C, 0x2C), ML(5, 0x6), ()),
    KC_RALT: KI('KC_RALT', LL(0, 0x0F, 0x1F, 0x2F), ML(5, 0xA), ()),
    KC_FN:   KI('KC_FN',   LL(2, 0x84, 0x74, 0x64), ML(5, 0xB), (KC_FN,)),
    KC_APP:  KI('KC_APP',  LL(2, 0x85, 0x75, 0x65), ML(5, 0xC), ()),
    KC_RCTL: KI('KC_RCTL', LL(2, 0x86, 0x76, 0x55), ML(5, 0xD), ()),
    KC_LEFT: KI('KC_LEFT', LL(2, 0x87, 0x66, 0x56), ML(5, 0xE), ()),
    KC_DOWN: KI('KC_DOWN', LL(2, 0x06, 0x16, 0x26), ML(5, 0xF), (KC_BACKLIGHT_BRDOWN,)),
    KC_RGHT: KI('KC_RGHT', LL(2, 0x05, 0x15, 0x25), ML(6, 0xF), ()),
    KC_KP_0: KI('KC_KP_0', LL(2, 0x04, 0x14, 0x24), ML(7, 0xF), ()),
    KC_PDOT: KI('KC_PDOT', LL(2, 0x03, 0x13, 0x23), ML(7, 0x7), ()),

    KC_NO:   KI('KC_NO',   LL(0, 0xFF, 0xFF, 0xFF), ML(7, 0x0), ()),
}


index_to_keycode = [[0] * 105 for i in range(2)]
keycode_to_index = [105] * 256  # 104 = KC_NO
matrix_to_index = [[105] * 16 for _ in range(8)]  # 104 = KC_NO
index_to_matrix = [ML(7, 0)] * 105  # (7, 0) is not mapped
index_to_led = [LL(0, 0xFF, 0xFF, 0xFF)] * 105  # (0, 0xFF, 0xFF, 0xFF) is not mapped
keycodes = {}
for i, keycode in enumerate(key_info):
    ki = key_info[keycode]
    index_to_keycode[0][i] = keycode
    for li, lk in enumerate(ki.additional_layers, 1):
        index_to_keycode[li][i] = lk
    keycode_to_index[keycode] = i
    matrix_to_index[ki.matrix_location.r][ki.matrix_location.c] = i
    index_to_matrix[i] = ki.matrix_location
    index_to_led[i] = ki.led_location
    keycodes[ki.keycode_name] = keycode


with open('../include/layout.h', 'w') as f:
    f.write(Template(filename='layout.h.tpl').render(**locals()))


