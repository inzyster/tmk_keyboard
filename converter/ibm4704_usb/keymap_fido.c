#include "keymap_common.h"
#include "led_stuff.h"
#include "debug.h"

#define KC_FSAV    KC_FN10
#define KC_FBLD    KC_FN11
#define KC_FFND    KC_FN12
#define KC_FDBZ    KC_FN13

enum function_id {
    FUNCTION_LED_WOO,
};

enum macro_id {
    MACRO_SAVE,
    MACRO_BUILD,
    MACRO_FIND,
    MACRO_DOUBLE_ZERO,
};

static inline void power_led_on(void)
{
    DDRD    |=  (1 << PORTD4);
    PORTD   |=  (1 << PORTD4); 
}

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
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,BSPC,BSPC,     PSCR,SLCK,PAUS,     NLCK,PSLS,PAST,PMNS, \
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     BSLS,     INS, HOME,PGUP,     P7,  P8,  P9,  PPLS, \
    FSAV,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT, ENT,      ENT,      DEL, END, PGDN,     P4,  P5,  P6,  EQL,  \
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,RSFT,          RSFT,     NO,  UP,  NO,       P1,  P2,  P3,  PENT, \
    LCTL,LGUI,LALT,          SPC,                     RALT,FN0,                RCTL,     LEFT,DOWN,RGHT,     P0,  FDBZ,PDOT,PENT  \
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
    GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,DEL, DEL, F5,       MPLY,MNXT,MPRV,     CALC,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     F10,      TRNS,TRNS,VOLU,     TRNS,TRNS,TRNS,TRNS, \
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     F11,      F9,  TRNS,VOLD,     TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FFND,TRNS,          F12,      FN20,PGUP,TRNS,     TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,               FBLD,     HOME,PGDN,END,      TRNS,TRNS,TRNS,TRNS  \
    ),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [10] = ACTION_MACRO(MACRO_SAVE),
    [11] = ACTION_MACRO(MACRO_BUILD),
    [12] = ACTION_MACRO(MACRO_FIND),
    [13] = ACTION_MACRO(MACRO_DOUBLE_ZERO),
    [20] = ACTION_FUNCTION(FUNCTION_LED_WOO),
};

/*
 * Functions
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case FUNCTION_LED_WOO: {
            if (event.pressed == false) {
                dprint("pattern fn triggered\n");
                led_pattern_t pattern;
                pattern = (led_pattern_t){ .pattern = 0b01010101, .length = 8, .remain = 8, .repeat = true };
                dprintf("pattern = %d, length = %d, remain = %d, repeat = %d\n", pattern.pattern, pattern.length, pattern.remain, pattern.repeat);
                led_set_pattern(pattern);
            } 
            break;
        }
    }
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case MACRO_SAVE:
            return (event.pressed ?
                    MACRO( D(LCTL), T(S), END ) :
                    MACRO( U(LCTL), END ));
        case MACRO_BUILD:
            return (event.pressed ?
                    MACRO( D(LCTL), T(B), END ) :
                    MACRO( U(LCTL), END ));
        case MACRO_FIND:
            return (event.pressed ?
                    MACRO( D(LCTL), T(F), END ) :
                    MACRO( U(LCTL), END ));
        case MACRO_DOUBLE_ZERO:
            return (event.pressed ?
                    MACRO( T(P0), W(25), T(P0), END ) :
                    MACRO_NONE );            
    }
    return MACRO_NONE;
}

/* stuff and things */

void hook_late_init(void) 
{
    power_led_on();
}

void hook_keyboard_loop(void) 
{
    led_timer_tick();
}

