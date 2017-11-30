#include "keymap_common.h"

#define KC_MSAV KC_FN1
#define KC_MBLD KC_FN2
#define KC_MFND KC_FN3

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP_EXT_ANSI(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,                   MPLY,
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NO,  NO,  NO,  MBLD,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,    NO,  NO,  F5,  F10,
    MSAV,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                         NO,  NO,  F11, F12,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,          UP,           NO,  NO,  F9,
    LCTL,LGUI,RALT,          SPC,                               FN0, RCTL,     LEFT,DOWN,RGHT,    NO,       PDOT,MFND
    ),
    KEYMAP_EXT_ANSI(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,                   TRNS,
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,MPRV,VOLU,    NLCK,EQL, PSLS,PAST,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,MNXT,VOLD,    P7,  P8,  P9,  PMNS,
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,                        P4,  P5,  P6,  PPLS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,          PGUP,         P1,  P2,  P3,
    TRNS,TRNS,LALT,          TRNS,                              TRNS,TRNS,     HOME,PGDN,END,     P0,       PDOT,PENT
    ),    
};

enum fido_macros {
    MA_SAVE,
    MA_BUILD,
    MA_FIND,
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_MACRO(MA_SAVE),
    [2] = ACTION_MACRO(MA_BUILD),
    [3] = ACTION_MACRO(MA_FIND),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case MA_SAVE: {
            return (event.pressed ? 
                    MACRO( D(LCTL), T(S), U(LCTL), END ) :
                    MACRO( D(LCTL), T(S), U(LCTL), END ));
            break;
        }
        case MA_BUILD: {
            return (event.pressed ? 
                    MACRO( D(LCTL), T(B), END ) :
                    MACRO( U(LCTL), END ));
            break;
        }
        case MA_FIND: {
            return (event.pressed ? 
                    MACRO( D(LCTL), T(F), END ) :
                    MACRO( U(LCTL), END ));
            break;
        }        
        default: break;
    }
    return MACRO_NONE;
}
