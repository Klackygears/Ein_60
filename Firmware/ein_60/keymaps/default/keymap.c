/* Copyright 2021 klackygears
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION,
    };

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------.  ,------.  ,----------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |  | Mute |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------|  `------'  |------+------+------+------+------+------|
     * | Func |   A  |   S  |   D  |   F  |   G  |            |   H  |   J  |   K  |   L  |   ;  | Enter|
     * |------+------+------+------+------+------|            |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |            |   N  |   M  |   ,  |   .  |   /  |  '   |
     * |------+------+------|--------------------+  ,------.  +--------------------|------+------+------|
     * | Ctrl |  `   | GUI  | Alt  |Lower |Space |  |Space |  |Space |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------'  `------'  `-----------------------------------------'
     */
    [_QWERTY] = LAYOUT_split_4x6_2( \
     KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,    KC_MUTE, KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
     MO(_FUNCTION), KC_A,   KC_S,    KC_D,    KC_F,       KC_G,             KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_ENT,
     OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,       KC_B,             KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
     KC_LCTL,       KC_GRV, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_SPC,  KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Lower
     * ,-----------------------------------------.  ,------.  ,-----------------------------------------.
     * | Esc  |   !  |   @  |   #  |   $  |   %  |  |      |  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+------|  `------'  |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |            |      |   _  |   +  |   {  |   }  |Enter |
     * |------+------+------+------+------+------|            |------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |            |      |      |      | Mute |      |  |   |
     * |------+------+------|--------------------+  ,------.  +--------------------|------+------+------|
     * |      |      |      |      |Lower | Bksp |  |      |  | Bksp |Raise | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------'  `------'  `-----------------------------------------'
     */
    [_LOWER] = LAYOUT_split_4x6_2( \
     KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,              _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
     KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             _______, _______, _______, KC_MUTE, _______, KC_PIPE,
     _______, _______,  _______, _______, _______, KC_BSPC,  _______,  KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),
    /* Raise
     * ,-----------------------------------------.  ,------.  ,-----------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |  |      |  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------|  `------'  |------+------+------+------+------+------|
     * |      |   4  |   5  |   6  |   +  |  F5  |            |  F6  |   -  |   =  |   [  |   ]  |Enter |
     * |------+------+------+------+------+------|            |------+------+------+------+------+------|
     * |Enter |   7  |   8  |   9  |   -  |  F11 |            |  F12 |ISO # |ISO / | Mute |      |   \  |
     * |------+------+------|--------------------+  ,------.  +--------------------|------+------+------|
     * |      |   ,  |   0  |  .   |Lower | Bksp |  |      |  | Bksp |Raise | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------'  `------'  `-----------------------------------------'
     */
    [_RAISE] = LAYOUT_split_4x6_2( \
     KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,     _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
     _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_F5,              KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
     KC_ENT,  KC_7,    KC_8,  KC_9,   KC_MINS, KC_F11,             KC_F12,  KC_NUHS, KC_NUBS, KC_MUTE, _______, KC_BSLS,
     _______, KC_COMM, KC_0,  KC_DOT, _______, KC_BSPC,  _______,  KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),
    /* Adjust (Lower + Raise)
     * ,-----------------------------------------.  ,------.  ,-----------------------------------------.
     * |      |      |      |      |      |      |  |      |  |      |RGBMOD|RGBVAI|RGBSAI|RGBHUI|caltde|
     * |------+------+------+------+------+------|  `------'  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |            |      |RGBRMO|RGBVAD|RGBSAD|RGBHUD|RGBTOG|
     * |------+------+------+------+------+------|            |------+------+------+------+------+------|
     * |      |      |      |      |      |      |            |      |      |      |      |      |BLSTEP|
     * |------+------+------|--------------------+  ,------.  +--------------------|------+------+------|
     * |      |      |      |      |      |      |  |      |  |      |      |      |      |      | RESET|
     * `-----------------------------------------'  `------'  `-----------------------------------------'
     */
    [_ADJUST] = LAYOUT_split_4x6_2( \
     _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, _______,
     _______, _______, _______, _______, _______, _______,          _______, RGB_RMOD,RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
     _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, BL_STEP,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
    ),
    /* Function
     * ,-----------------------------------------.  ,------.  ,-----------------------------------------.
     * |      |      |      |      |      |      |  |      |  |      |      |  Up  |      |      |      |
     * |------+------+------+------+------+------|  `------'  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |            |      | Left | Down |Right |      |      |
     * |------+------+------+------+------+------|            |------+------+------+------+------+------|
     * | Caps |      |      |      |      |      |            |      |      |      |      |      |      |
     * |------+------+------|--------------------+  ,------.  +--------------------|------+------+------|
     * |      |      |      |      |      |      |  |      |  |      |      |      |      |      |      |
     * `-----------------------------------------'  `------'  `-----------------------------------------'
     */
    [_FUNCTION] = LAYOUT_split_4x6_2( \
     _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
     _______, _______, _______, _______, _______, _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
     KC_CAPS, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

void oled_task_user(void) {
    render_status();
    oled_write_ln_P(PSTR("\n\n"), false);
    render_logo();
}
#endif


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}
