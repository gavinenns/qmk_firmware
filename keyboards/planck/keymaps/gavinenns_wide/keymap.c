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
  _LOWER,
  _RAISE,
  _MEDIA,
  _ADJUST,
  _GAME,
  _SUPER,
  _GMRAIS
};

enum custom_keycodes {
    KC_DTQS = SAFE_RANGE,
    KC_CMEX,
    G_START,
    G_EXIT,
    GM_RAIS
};

#define LK_LY KC_NO

#define ES_FN LT(_FUNCTION, KC_ESC)
#define TB_SY LT(_SYMBOL, KC_TAB)
#define SP_NM LT(_NUMBER, KC_SPC)
#define EN_AR LT(_ARROW, KC_ENT)
#define BS_NV LT(_NAVIGATION, KC_BSPC)
#define DL_BK LT(_BRACKET, KC_DEL)

#define MO_A RCTRL_T(KC_A)
#define MO_S RALT_T(KC_S)
#define MO_D RGUI_T(KC_D)
#define MO_F RSFT_T(KC_F)
#define MO_G MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_G)
#define MO_H MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_H)
#define MO_J RSFT_T(KC_J)
#define MO_K RGUI_T(KC_K)
#define MO_L RALT_T(KC_L)
#define MO_QT RCTRL_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,  KC_VOLD,  KC_VOLU,  KC_Y,  KC_U, KC_I,       KC_O, KC_P,
    MO_A,   MO_S,  MO_D,  MO_F,  MO_G,  KC_MUTE,  KC_PLAY,  MO_H,  MO_J, MO_K,       MO_L, MO_QT,
    KC_Z,   KC_X,  KC_C,  KC_V,  KC_B,  KC_PREV,  KC_NEXT,  KC_N,  KC_M, KC_CMEX, KC_DTQS, KC_SCLN,
    LY_LK, KC_NO, ES_FN, TB_SY, SP_NM,    SP_NM,    EN_AR, EN_AR, BS_NV, DL_BK,     KC_NO, KC_NO
),

[_NUMBER] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_TILD,    KC_7, KC_8,   KC_9, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_SLSH,    KC_4, KC_5,   KC_6, KC_MINS,
  _______, _______, _______, _______, _______, _______, _______, KC_ASTR,    KC_1, KC_2,   KC_3, KC_PLUS,
  _______, _______, _______, _______, _______, _______,  KC_ENT,  KC_ENT, KC_BSPC, KC_0, KC_DOT,  KC_EQL
),

[_SYMBOL] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_GRV,  KC_AMPR, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,
  _______, _______, _______, _______, _______, _______,  KC_ENT,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
),

[_FUNCTION] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_F7, KC_F8,   KC_F9, KC_F15,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_F4, KC_F5,   KC_F6, KC_F14,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_F1, KC_F2,   KC_F3, KC_F13,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11,  KC_F12
),

[_ARROW] = LAYOUT_planck_grid(
  _______, _______,   KC_UP,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_NAVIGATION] = LAYOUT_planck_grid(
  _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, KC_HOME, KC_PGDN,  KC_END, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_BRACKET] = LAYOUT_planck_grid(
  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______,  _______, _______, _______,
  KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
  _______, RESET,     DEBUG, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______,   MI_ON,  MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
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
    case G_START:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
          PLAY_SONG(zelda_song);
        #endif
        layer_on(_GAME);
      }
      return false;
    case G_EXIT:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
          PLAY_SONG(bloop_song);
        #endif
        g_exit_timer = timer_read();
        g_exit_pressed = true;
      } else {
        g_exit_pressed = false;
      }
      return false;
    case GM_RAIS:
      layer_state ^= (1 << _RAISE) | (1 << _GMRAIS);
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
  return update_tri_layer_state(state, _NUMBER, _ARROW, _ADJUST);
}

void matrix_scan_user(void) {
    if ( g_exit_pressed && timer_elapsed(g_exit_timer) > 500 ) {
      g_exit_pressed = false;
      #ifdef AUDIO_ENABLE
        PLAY_SONG(mario_song);
      #endif
      layer_off(_GAME);
    }
}
