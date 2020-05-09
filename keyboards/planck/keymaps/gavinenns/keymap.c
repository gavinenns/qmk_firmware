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


#define ZELDA_NOTES  \
    H__NOTE(_G5 ),     \
    H__NOTE(_FS5),     \
    H__NOTE(_DS5),     \
    H__NOTE(_A4 ),     \
    H__NOTE(_GS4),     \
    H__NOTE(_E5 ),     \
    H__NOTE(_GS5),     \
    HD_NOTE(_C6 )

#define BLOOP_NOTES \
  E__NOTE(_C5), \
  E__NOTE(_CS5), \
  Q__NOTE(_D5)

#define MARIO_NOTES \
  H__NOTE(_B5), \
  H__NOTE(_F6), \
  H__NOTE(_REST), \
  H__NOTE(_F6), \
  E__NOTE(_REST), \
  W__NOTE(_F6), \
  Q__NOTE(_REST), \
  W__NOTE(_E6), \
  Q__NOTE(_REST), \
  W__NOTE(_D6), \
  Q__NOTE(_REST), \
  H__NOTE(_G5), \
  H__NOTE(_E5), \
  E__NOTE(_REST), \
  Q__NOTE(_G4), \
  E__NOTE(_REST), \
  H__NOTE(_E5), \
  HD_NOTE(_C5)

#ifdef AUDIO_ENABLE
  float zelda_song[][2] = SONG(ZELDA_NOTES);
  float bloop_song[][2] = SONG(BLOOP_NOTES);
  float mario_song[][2] = SONG(MARIO_NOTES);
#endif


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


#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define MED_ESC LT(_MEDIA, KC_ESC)
#define MED_BSP LT(_MEDIA, KC_BSPC)
#define SUPER MO(_SUPER)
#define GUI_P0 RGUI_T(KC_P0)
#define RS_PENT RSFT_T(KC_PENT)

#define S_(x) LCTL(LALT(LGUI(x)))

#define CMD_TLD LGUI(KC_GRV)
#define CMD_TAB LCTL(KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    MED_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,       KC_P,  MED_BSP,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_CMEX, KC_DTQS,   KC_UP,  KC_SFTENT,
    SUPER,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,  LOWER,   RAISE,   RAISE,   KC_RGUI, KC_LEFT, KC_DOWN,  KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_DEL,
    _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______, _______, _______, KC_EQL,  KC_UNDS, KC_PIPE, KC_BSLS,
    _______, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, _______, _______, _______, _______, KC_SLSH, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
),

[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_P7,   KC_P8,    KC_P9,    KC_0, KC_BSPC,
    _______, _______, _______, _______, _______, _______, KC_PSLS,   KC_P4,   KC_P5,    KC_P6, KC_PAST, KC_PEQL,
    _______, _______, _______, _______, _______, _______, KC_PMNS,   KC_P1,   KC_P2,    KC_P3, KC_PPLS, RS_PENT,
    _______, _______, _______, _______, _______, _______, _______, _______,   GUI_P0, KC_PDOT, _______, _______
),

[_MEDIA] = LAYOUT_planck_grid(
  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_EJCT, KC_MUTE, KC_VOLD, KC_VOLU, _______,
  G_START,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
  CK_TOGG,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______,  KC_F13,  KC_F14,  KC_F15,  KC_F16, _______,
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


[_ADJUST] = LAYOUT_planck_grid(
  _______, RESET,     DEBUG, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______,   MI_ON,  MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_SUPER] = LAYOUT_planck_grid(
  CMD_TLD, S_(KC_1), S_(KC_2), S_(KC_3), S_(KC_4), _______, _______, _______, _______,  S_(KC_MINS), S_(KC_EQL), _______,
  CMD_TAB, _______, _______, _______, S_(KC_F), _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, S_(KC_C), _______, _______, S_(KC_N), S_(KC_M), _______,  _______, S_(KC_UP), _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  S_(KC_LEFT), S_(KC_DOWN), S_(KC_RIGHT)
),

[_GAME] = LAYOUT_planck_grid(
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_ENT,
  _______, _______, _______, _______,  KC_SPC,  KC_SPC, GM_RAIS, GM_RAIS, G_EXIT,   _______, _______, _______
),

[_GMRAIS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_8,     KC_9, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,     KC_6, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,     KC_3, _______, _______,
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
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
