/* Copyright 2022 Gondolindrim
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
#include "rgblight.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        // clang-format off
        KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        CW_TOGG, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN,
		KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,   KC_END,
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, MO(2), KC_LEFT, KC_DOWN, KC_RGHT
        // clang-format on
        ),
    [1] = LAYOUT_65_ansi_blocker(
        // clang-format off
        KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_TRNS, KC_TRNS, RSFT_T(KC_J), RGUI_T(KC_K), LALT_T(KC_L), RCTL_T(KC_SCLN), KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS
        // clang-format on
        ),
    [2] = LAYOUT_65_ansi_blocker(
        // clang-format off
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(1),
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        // clang-format on
        )};

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(0, 0, 0);
}

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_noeeprom(0, 0, 255);
    } else {
        rgblight_sethsv_noeeprom(0, 0, 0);
    }
}
