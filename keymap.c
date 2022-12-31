#include QMK_KEYBOARD_H
#include "muse.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCS 3
#define _PLANK 4

/* ENTER when tapped / SHIFT when held */
#define KC_ESFT MT(MOD_RSFT, KC_ENT)

/* LT(layer, kc)
    Momentarily activates *layer* when held, and sends *kc* when tapped.
    Only supports layers 0-15. */

/* LM(layer, mod)
    Momentarily activates *layer*, but with modifier(s) *mod* active.
    Only supports layers 0-15 and the left modifiers: MOD_LCTL, MOD_LSFT, MOD_LALT, MOD_LGUI.
    These modifiers can be combined using bitwise OR, e.g. LM(_LOWER, MOD_LCTL | MOD_LGUI). */

#define QWERTY TO(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCS TO(_FUNCS)
#define PLANK TO(_PLANK)

enum unicode_names {
    KC_EURO,
    FI_UADIA,
    FI_LADIA,
    FI_UODIA,
    FI_LODIA,
    IT_UAGRV,
    IT_LAGRV,
    IT_UEGRV,
    IT_LEGRV,
    IT_UOGRV,
    IT_LOGRV,
    IT_UUGRV,
    IT_LUGRV
};

const uint32_t PROGMEM unicode_map[] = {
    [KC_EURO] = 0x20AC,  // €
    [FI_UADIA] = 0x00C4, // Ä
    [FI_LADIA] = 0x00E4, // ä
    [FI_UODIA] = 0x00D6, // Ö
    [FI_LODIA] = 0x00F6, // ö
    [IT_UAGRV] = 0x00C0, // À
    [IT_LAGRV] = 0x00E0, // à
    [IT_UEGRV] = 0x00C8, // È
    [IT_LEGRV] = 0x00E8, // è
    [IT_UOGRV] = 0x00D2, // Ò
    [IT_LOGRV] = 0x00F2, // ò
    [IT_UUGRV] = 0x00D9, // Ù
    [IT_LUGRV] = 0x00F9, // ù
};

#define EURO X(KC_EURO)
#define FI_ADIA XP(FI_LADIA, FI_UADIA)
#define FI_ODIA XP(FI_LODIA, FI_UODIA)
#define IT_AGRV XP(IT_LAGRV, IT_UAGRV)
#define IT_EGRV XP(IT_LEGRV, IT_UEGRV)
#define IT_OGRV XP(IT_LOGRV, IT_UOGRV)
#define IT_UGRV XP(IT_LUGRV, IT_UUGRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
│ Esc   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │  Bksp │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│ Tab   │   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │   '   │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│ Shift │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │ Enter │
├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
│ Ctrl  │  Alt  │ Super │       │ Raise │     Space     │ Lower │  Up   │ Down  │ Left  │ Right │
└───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘ */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESFT,
    KC_LCTL, KC_LOPT, KC_LCMD, XXXXXXX, RAISE, KC_SPC, LOWER, KC_UP, KC_DOWN, KC_LEFT, KC_RGHT
),

/* Lower - FI
┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
│       │       │       │       │       │       │       │       │       │   Ö   │       │   Del │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │   Ä   │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │   -   │   +   │       │ Shift │
├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
│   1   │   2   │   3   │   4   │   5   │       =       │   ▽   │ Funcs │ Super │  Alt  │  Ctrl │
└───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘ */
[_LOWER] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FI_ODIA, XXXXXXX, KC_DEL,
    XXXXXXX, FI_ADIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_PPLS, XXXXXXX, KC_RSFT,
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_PEQL, KC_TRNS, FUNCS, KC_LCMD, KC_LOPT, KC_LCTL
),

/* Raise - IT
┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
│       │       │       │   È   │       │       │       │   Ù   │       │   Ò   │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │   À   │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│ Shift │       │       │       │       │       │       │       │   [   │   ]   │   \   │   `   │
├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
│ Ctrl  │  Alt  │ Super │ Plank │   ▽   │       _       │   6   │   7   │   8   │   9   │   0   │
└───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘ */
[_RAISE] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, IT_EGRV, XXXXXXX, XXXXXXX, XXXXXXX, IT_UGRV, XXXXXXX, IT_OGRV, XXXXXXX, XXXXXXX,
    XXXXXXX, IT_AGRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    KC_LCTL, KC_LOPT, KC_LCMD, PLANK, KC_TRNS, KC_UNDS, KC_6, KC_7, KC_8, KC_9, KC_0
),

/* Funcs
┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
│       │  F1   │  F2   │  F3   │  F4   │       │       │       │       │       │       │  Exit │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │  F5   │  F6   │  F7   │  F8   │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │  F9   │  F10  │  F11  │  F12  │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │               │       │       │ Super │  Alt  │  Ctrl │
└───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘ */
[_FUNCS] = LAYOUT_planck_mit(
    XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,
    XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCMD, KC_LOPT, KC_LCTL
),

/* Plank
┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
│ Reset │       │       │       │       │       │       │       │       │       │       │  Exit │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │ Linux │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │  Mac  │       │       │       │   RGB │
├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │               │       │       │       │       │       │
└───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘ */
[_PLANK] = LAYOUT_planck_mit(
    QK_BOOTLOADER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UNICODE_MODE_LINUX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UNICODE_MODE_MACOS, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        rgblight_setrgb(0x00, 0x00, 0x00);
        break;
    case _FUNCS:
        rgblight_setrgb(0x00, 0x00, 0x96);
        break;
    case _PLANK:
        rgblight_setrgb(0x96, 0x00, 0x00);
        break;
    default:
        rgblight_setrgb(0x00, 0x00, 0x00);
        break;
    }
    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        if (IS_LAYER_ON(_QWERTY)) {
            tap_code16(S(G(KC_Z)));
        } else if (IS_LAYER_ON(_PLANK)) {
            tap_code16(KC_VOLU);
        }
    } else {
        if (IS_LAYER_ON(_QWERTY)) {
            tap_code16(G(KC_Z));
        } else if (IS_LAYER_ON(_PLANK)) {
            tap_code16(KC_VOLD);
        }
    }
    return true;
}
