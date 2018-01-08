#include "keymap_common.h"
#include "debug.h"

#define KC_FTPZ    KC_FN10
#define KC_FDBZ    KC_FN11

enum macro_id {
    MACRO_TRIPLE_ZERO,
    MACRO_DOUBLE_ZERO,
};

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,---------------------------------------------------------------.  ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|BS |BS |F21|  |PSC|SLK|PAU| |F1 |F2 |F3 |F4 |
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|F22|  |Ins|Hom|PgU| |F5 |F6 |F7 |F8 |
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ret|Ret |F23|  |Del|End|PgD| |F9 |F10|F11|F12|
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shf|Shift |F24|  |   |Up |   | |F13|F14|F15|F16|
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Fn0  |Gui|Alt  |         Space             |Alt* |Gui|Fn0      |  |Lef|Dow|Rig| |F17|F18|F19|F20|
     * `---------------------------------------------------------------'  `-----------' `---------------'
     */
    KEYMAP_ALPS102(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,BSPC,NO,       PSCR,SLCK,PAUS,     NLCK,PSLS,PAST,PMNS, \
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     NO,       INS, HOME,PGUP,     P7,  P8,  P9,  EQL,  \
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT, ENT,      NO,       DEL, END, PGDN,     P4,  P5,  P6,  PPLS,  \
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,RSFT,          NO,       NO,  UP,  NO,       P1,  P2,  P3,  PENT, \
    LCTL,LGUI,LALT,          SPC,                     RALT,FN0,                RCTL,     LEFT,DOWN,RGHT,     P0,  FTPZ,PDOT,PENT  \
    ),

    /* Layer 1:
     * ,---------------------------------------------------------------.  ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|BS |BS |F21|  |VoD|VoU|Mut| |F1 |F2 |F3 |F4 |
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|F22|  |Ins|Hom|PgU| |F5 |F6 |F7 |F8 |
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ret|Ret |F23|  |Del|End|PgD| |F9 |F10|F11|F12|
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shf|Shift |F24|  |   |PgU|   | |F13|F14|F15|F16|
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Fn0  |Gui|Alt  |         Space             |Alt* |Gui|Fn0      |  |Hom|PgD|End| |F17|F18|F19|F20|
     * `---------------------------------------------------------------'  `-----------' `---------------'
     */
    KEYMAP_ALPS102(
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, DEL, TRNS,     TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     PSCR,SLCK,PAUS,     TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,     TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,               TRNS,     TRNS,TRNS,TRNS,     TRNS,FDBZ,TRNS,TRNS  \
    ),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [10] = ACTION_MACRO(MACRO_TRIPLE_ZERO),
    [11] = ACTION_MACRO(MACRO_DOUBLE_ZERO),
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case MACRO_TRIPLE_ZERO:
            return (event.pressed ?
                    MACRO( T(P0), W(45), T(P0), W(45), T(P0), END ) :
                    MACRO_NONE );            
        case MACRO_DOUBLE_ZERO:
            return (event.pressed ?
                    MACRO( T(P0), W(45), T(P0), END ) :
                    MACRO_NONE );                                
    }
    return MACRO_NONE;
}

