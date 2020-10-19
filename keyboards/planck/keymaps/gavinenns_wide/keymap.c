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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NUMLOCK,
  _NUMBER,
  _NUMPAD,
  _SYMBOL,
  _NAVIGATION,
  _BRACKET,
  _FUNCTION,
  _GAME,
  _LAYERLOCK,
  _ADJUST,
};

enum custom_keycodes {
    KC_DTQS = SAFE_RANGE,
    KC_CMEX
};

#define ___x___ KC_NO

#define LY_LK MO(_LAYERLOCK)

#define TB_SY LT(_SYMBOL, KC_TAB)
#define SP_NM LT(_NUMBER, KC_SPC)
#define SP_NMPD LT(_NUMPAD, KC_SPC)
#define EN_NV LT(_NAVIGATION, KC_ENT)
#define BS_BK LT(_BRACKET, KC_BSPC)
#define DE_FN LT(_FUNCTION, KC_DEL)

#define MOD_1 KC_RCTL
#define MOD_2 KC_RALT
#define MOD_3 KC_RCMD
#define MOD_4 KC_RSFT
#define MOD_5 LCTL(LALT(KC_LGUI))

#define MO_1(x) RCTL_T(x)
#define MO_2(x) RALT_T(x)
#define MO_3(x) RGUI_T(x)
#define MO_4(x) RSFT_T(x)
#define MO_5(x) MT(MOD_LCTL | MOD_LALT | MOD_LGUI, x)


#define MO_A MO_1(KC_A)
#define MO_S MO_2(KC_S)
#define MO_D MO_3(KC_D)
#define MO_F MO_4(KC_F)
#define MO_G MO_5(KC_G)
#define MO_H MO_5(KC_H)
#define MO_J MO_4(KC_J)
#define MO_K MO_3(KC_K)
#define MO_L MO_2(KC_L)
#define MO_QT MO_1(KC_QUOT)

#define LK_FN TG(_FUNCTION)
#define LK_SY TG(_SYMBOL)
#define LK_NM TG(_NUMBER)
#define LK_NMPD TG(_NUMLOCK)
#define LK_NV TG(_NAVIGATION)
#define LK_BK TG(_BRACKET)
#define LK_GM TG(_GAME)

#define CLR_LK TO(_QWERTY)

#define CMD_Z LGUI(KC_Z)
#define CMD_X LGUI(KC_X)
#define CMD_C LGUI(KC_C)
#define CMD_V LGUI(KC_V)
#define CMD_TIL LGUI(KC_TILD)
#define CMD_TAB LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_VOLD,  KC_VOLU,  KC_Y,  KC_U, KC_I,       KC_O, KC_P,
    MO_A,    MO_S,    MO_D,  MO_F,  MO_G,  KC_MUTE,  KC_MPLY,  MO_H,  MO_J, MO_K,       MO_L, MO_QT,
    KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,  KC_MPRV,  KC_MNXT,  KC_N,  KC_M, KC_CMEX, KC_DTQS, KC_SCLN,
    LY_LK, CLR_LK, KC_GESC, TB_SY, SP_NM,    SP_NM,    EN_NV, EN_NV, BS_BK, DE_FN,    CLR_LK, LY_LK
),

[_NUMLOCK] = LAYOUT_planck_grid(
  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,  _______, SP_NMPD, SP_NMPD, _______, _______, _______,  _______, _______, _______
),

[_NUMBER] = LAYOUT_planck_grid(
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  KC_GRV,    KC_7, KC_8,   KC_9, ___x___,
    MOD_1,   MOD_2,   MOD_3,   MOD_4,   MOD_5, ___x___, ___x___, KC_SLSH,    KC_4, KC_5,   KC_6, KC_MINS,
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_ASTR,    KC_1, KC_2,   KC_3, KC_PLUS,
  _______, _______,  KC_ESC,  KC_TAB, _______, _______, _______, _______, KC_BSPC, KC_0, KC_DOT,  KC_EQL
),

[_NUMPAD] = LAYOUT_planck_grid(
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  KC_GRV,    KC_P7, KC_P8,   KC_P9, ___x___,
    MOD_1,   MOD_2,   MOD_3,   MOD_4,   MOD_5, ___x___, ___x___, KC_PSLS,    KC_P4, KC_P5,   KC_P6, KC_PMNS,
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_PAST,    KC_P1, KC_P2,   KC_P3, KC_PPLS,
  _______, _______,  KC_ESC,  KC_TAB, _______, _______, KC_PENT, KC_PENT, KC_BSPC, KC_P0, KC_PDOT,  KC_PEQL
),

[_SYMBOL] = LAYOUT_planck_grid(
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_TILD,  KC_AMPR, ___x___, ___x___, ___x___,
    MOD_1,   MOD_2,   MOD_3,   MOD_4,   MOD_5, ___x___, ___x___, KC_BSLS, KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS,
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,
  _______, _______,  KC_ESC, _______,  KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
),

[_NAVIGATION] = LAYOUT_planck_grid(
  CMD_TIL, KC_PGUP,   KC_UP,  KC_PGDN, KC_HOME, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  CMD_TAB, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_END, ___x___, ___x___,   MOD_5,   MOD_4,    MOD_3,   MOD_2,   MOD_1,
    CMD_Z,   CMD_X,   CMD_C,    CMD_V, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  _______, _______,  KC_ESC,   KC_TAB, _______, _______, _______, _______, KC_BSPC,   KC_DEL, _______, _______
),

[_BRACKET] = LAYOUT_planck_grid(
  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, ___x___, ___x___, ___x___,   MOD_5,   MOD_4,    MOD_3,   MOD_2,   MOD_1,
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  _______, _______,  KC_ESC,  KC_TAB,  KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT, _______,   KC_DEL, _______, _______
),

[_FUNCTION] = LAYOUT_planck_grid(
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  KC_F7,  KC_F8,  KC_F9, KC_F15,
    MOD_1,   MOD_2,   MOD_3,   MOD_4,   MOD_5, ___x___, ___x___, ___x___,  KC_F4,  KC_F5,  KC_F6, KC_F14,
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  KC_F1,  KC_F2,  KC_F3, KC_F13,
  _______, _______, _______,  KC_TAB, KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT, KC_BSPC, KC_F10, KC_F11, KC_F12
),

[_GAME] = LAYOUT_planck_grid(
   KC_ESC,    KC_Q,    KC_W,     KC_E,    KC_R,    KC_3,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0, ___x___,
   KC_TAB,    KC_A,    KC_S,     KC_D,    KC_F,    KC_2,    KC_5, ___x___, ___x___,  ___x___,   KC_UP, ___x___,
  KC_LSFT,    KC_Z,    KC_X,     KC_C,    KC_V,    KC_1,    KC_4, ___x___, ___x___,  KC_LEFT, KC_DOWN, KC_RIGHT,
  KC_LCTL, KC_LCTL, KC_LALT,  KC_LGUI,  KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT, KC_BSPC,   KC_DEL, _______, _______
),

[_LAYERLOCK] = LAYOUT_planck_grid(
  ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  _______, LK_NMPD,   LK_FN,    LK_SY,   LK_NM,   LK_NM,   LK_NV,   LK_NV,    LK_BK, ___x___,   LK_GM, _______
),

[_ADJUST] = LAYOUT_planck_grid(
  ___x___, RESET,     DEBUG, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, ___x___, ___x___,
  ___x___, ___x___, ___x___,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, ___x___, ___x___,  ___x___, ___x___, ___x___,
  ___x___, ___x___, ___x___, ___x___, ___x___,   MI_ON,  MI_OFF, TERM_ON, TERM_OFF, ___x___, ___x___, ___x___,
  ___x___, ___x___, ___x___, ___x___, _______, _______, _______, _______, ___x___,  ___x___, ___x___, ___x___
)

};

uint16_t g_exit_timer;
bool g_exit_pressed = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_DTQS:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SLSH);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_SLSH);
        unregister_code(KC_DOT);
      }
      return false;
    case KC_CMEX:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_1);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_1);
        unregister_code(KC_COMM);
      }
      return false;
    default:
      return true;
  }
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NUMBER, _NAVIGATION, _ADJUST);
}
