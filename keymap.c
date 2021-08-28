/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// screen capture dialog
#define GUI_CAP LSFT(LGUI(KC_5))
// put screens to sleep
#define GUI_SLP LSFT(LCTL(KC_POWER))

// Window manager keys
#define WM_FULL LCTL(LGUI(KC_F))
#define WM_NEXT LCTL(KC_RGHT)
#define WM_PREV LCTL(KC_LEFT)
#define WM_NW   LCTL(LALT(KC_U))
#define WM_N    LCTL(LALT(KC_UP))
#define WM_NE   LCTL(LALT(KC_I))
#define WM_E    LCTL(LALT(KC_RGHT))
#define WM_SE   LCTL(LALT(KC_K))
#define WM_S    LCTL(LALT(KC_DOWN))
#define WM_SW   LCTL(LALT(KC_J))
#define WM_W    LCTL(LALT(KC_LEFT))
#define WM_CNTR LCTL(LALT(KC_C))

// home row mods
#define MT_A    LCTL_T(KC_A)
#define MT_S    LALT_T(KC_S)
#define MT_D    LGUI_T(KC_D)
#define MT_F    LSFT_T(KC_F)
#define MT_J    RSFT_T(KC_J)
#define MT_K    RGUI_T(KC_K)
#define MT_L    RALT_T(KC_L)
#define MT_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_LCTL, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, _______, KC_ENT,  KC_SPC,  RAISE,   KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
),

[_RAISE] = LAYOUT_planck_grid(
  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  _______, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
),

[_ADJUST] = LAYOUT_planck_grid(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, WM_PREV, WM_NW,   WM_N,    WM_NE,   GUI_CAP,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, KC_VOLD, WM_FULL, WM_W,    WM_CNTR, WM_E,    XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, KC_MUTE, WM_NEXT, WM_SW,   WM_S,    WM_SE,   GUI_SLP,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, _______, KC_ENT,  KC_SPC,  _______, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
