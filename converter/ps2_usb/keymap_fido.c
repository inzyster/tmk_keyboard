#include "keymap_common.h"
#include "action_util.h"
#include "debug.h"

#define MSAV FN9
#define FCLS FN10
#define FCRS FN11
#define FCLC FN12
#define FCRC FN13
#define FCLA FN14
#define FCRA FN15

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |Pwr|Slp|Wak|
     * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspa| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
     * |-----------------------------------------------------------| `-----------' |-----------|  +|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|   |
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
     * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
     * |Ctrl |Gui |Alt |         Space         |Alt |Gui |Menu|Ctrl| |Lef|Dow|Rig| |      0|  .|   |
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    KEYMAP_ISO(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,FN0, BRK,
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,          DEL, END, PGDN,    P7,  P8,  P9,
    MSAV,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,ENT,                         P4,  P5,  P6,  PPLS,
    FCLS,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     FCRS,          UP,           P1,  P2,  P3,
    FCLC,NO  ,FCLA,          SPC,                     FCRA,NO,  NO,  FCRC,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),
    KEYMAP_ISO(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,
    GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    MPRV,MNXT,MPLY,VOLD,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,VOLU,
    LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     RSFT,          TRNS,         TRNS,TRNS,TRNS,
    LCTL,TRNS,LGUI,          TRNS,                    RALT,TRNS,TRNS,RCTL,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),
    KEYMAP_ISO(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,          TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),    
};

enum fido_macros {
    MA_SAVE,
};

enum fido_functions {
    FN_CADET_LSHIFT,
    FN_CADET_RSHIFT,
    FN_CADET_LCTRL,
    FN_CADET_RCTRL,
    FN_CADET_LALT,
    FN_CADET_RALT,
};

const action_t PROGMEM fn_actions[] = {   
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SLCK), 
    [9] = ACTION_MACRO(MA_SAVE),
    [10] = ACTION_FUNCTION_TAP(FN_CADET_LSHIFT),
    [11] = ACTION_FUNCTION_TAP(FN_CADET_RSHIFT),
    [12] = ACTION_FUNCTION_TAP(FN_CADET_LCTRL),
    [13] = ACTION_FUNCTION_TAP(FN_CADET_RCTRL),
    [14] = ACTION_FUNCTION_TAP(FN_CADET_LALT),
    [15] = ACTION_FUNCTION_TAP(FN_CADET_RALT),
};


/*
void space_cadet(keyrecord_t *record) {
    if (record->event.pressed) {
        if (record->tap.count > 0 && !record->tap.interrupted) {
            if (record->tap.interrupted) {
                dprint("tap interrupted\n");
                register_code(KC_NUBS);
            }
        } else {
            register_code(KC_NUBS);
        }
    } else {
        if (record->tap.count > 0 && !(record->tap.interrupted)) {
            if (record->tap.count == 1) {
                register_code(KC_LBRACKET);
                unregister_code(KC_LBRACKET);
            }
            else if (record->tap.count > 1) {
                register_code(KC_BSPACE);
                unregister_code(KC_BSPACE);
                if (record->tap.count == 2) {                
                    register_code(KC_RBRACKET);
                    unregister_code(KC_RBRACKET);
                }
                else if (record->tap.count == 3) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                }
                else if (record->tap.count == 4) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_0);
                    unregister_code(KC_0);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                }
            }
            //record->tap.count = 0;  // ad hoc: cancel tap
        } else {
            unregister_code(KC_NUBS);
        }
    }    
}*/

void fn_cadet(keyrecord_t *record, uint8_t mod_to_apply, uint8_t key, uint8_t original_mod) {
    if (record->event.pressed) {
        if (record->tap.count > 0 && !record->tap.interrupted) {
            if (record->tap.interrupted) {
                dprint("tap interrupted\n");
                register_mods(MOD_BIT(original_mod));
            }
        } else {
            register_mods(MOD_BIT(original_mod));
        }
    } else {
        if (record->tap.count > 0 && !(record->tap.interrupted)) {
            if (mod_to_apply != KC_NO) {
                add_weak_mods(MOD_BIT(mod_to_apply));
                send_keyboard_report();
            }
            register_code(key);
            unregister_code(key);
            if (mod_to_apply != KC_NO) {
                del_weak_mods(MOD_BIT(mod_to_apply));
                send_keyboard_report();
            }
            record->tap.count = 0;  // ad hoc: cancel tap
        } else {
            unregister_mods(MOD_BIT(original_mod));
        }
    }    
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    /*if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    if (record->tap.finished) dprint("f");
    dprint("\n");*/
    
    switch (id) {
        case FN_CADET_LSHIFT: {
            fn_cadet(record, KC_LSHIFT, KC_LBRACKET, KC_LSHIFT);
            break;
        }
        case FN_CADET_RSHIFT: {
            fn_cadet(record, KC_RSHIFT, KC_RBRACKET, KC_RSHIFT);
            break;
        }
        case FN_CADET_LCTRL: {
            fn_cadet(record, KC_LSHIFT, KC_9, KC_LCTRL);
            break;
        }
        case FN_CADET_RCTRL: {
            fn_cadet(record, KC_RSHIFT, KC_0, KC_RCTRL);
            break;
        }
        case FN_CADET_LALT: {
            fn_cadet(record, KC_NO, KC_LBRACKET, KC_LALT);
            break;
        }
        case FN_CADET_RALT: {
            fn_cadet(record, KC_NO, KC_RBRACKET, KC_RALT);
            break;
        }
        default: break;
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case MA_SAVE: {
            return (event.pressed ? 
                    MACRO( D(LCTL), T(S), END ) :
                    MACRO( U(LCTL), END ));
            break;
        }
        default: break;
    }
    return MACRO_NONE;
}
