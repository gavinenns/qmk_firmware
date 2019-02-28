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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _SHIFT,
  _LOWER,
  _RAISE,
  _MEDIA,
  _ADJUST,
  _GAME,
  _SUPER
};

enum custom_keycodes {
    KC_DTQS = SAFE_RANGE,
    KC_CMEX
};


#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define MED_ESC LT(_MEDIA, KC_ESC)
#define MED_BSP LT(_MEDIA, KC_BSPC)
#define SUPER MO(_SUPER)
#define GUI_P0 RGUI_T(KC_P0)
#define LSFT_L MO(_SHIFT)
#define RS_ENT LT(_SHIFT, KC_ENT)
#define RS_PENT LT(_SHIFT, KC_PENT)
#define SFTIT_L LCTL(LALT(LGUI(KC_LEFT)))
#define SFTIT_R LCTL(LALT(LGUI(KC_RIGHT)))
#define SFTIT_U LCTL(LALT(LGUI(KC_UP)))
#define SFTIT_D LCTL(LALT(LGUI(KC_DOWN)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    MED_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,   MED_BSP,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
    LSFT_L, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA, KC_DOT,    KC_UP,  RS_ENT,
    SUPER,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,  LOWER,   RAISE,   RAISE,    KC_RGUI, KC_LEFT, KC_DOWN,   KC_RGHT
),

[_SHIFT] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM,  KC_QUES, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,     KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,   KC_CIRC,   KC_AMPR,    KC_ASTR,    KC_UNDS,  KC_MINS, KC_DEL,
    _______, _______,   _______,   KC_LCBR, KC_RCBR,   _______,   _______,   KC_LPRN,    KC_RPRN,    KC_EQL,  KC_PLUS, KC_BSLS,
    _______, _______,   _______,   KC_LBRC, KC_RBRC,   _______,   _______,   KC_LABK,    KC_RABK,    _______, KC_PGUP, _______,
    _______, _______,   _______,   _______, _______,   _______,   _______,   _______,    _______,    KC_HOME, KC_PGDN, KC_END
),

[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,     KC_P7,    KC_P8,    KC_P9,    KC_0, KC_BSPC,
    _______, _______,   _______,   _______,   _______,   KC_PSLS,   KC_PAST,     KC_P4,    KC_P5,    KC_P6, KC_PIPE, KC_SLSH,
    _______, _______,   _______,   _______,   _______,   KC_PMNS,   KC_PPLS,     KC_P1,    KC_P2,    KC_P3, KC_PEQL, RS_PENT,
    _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,    GUI_P0, KC_PDOT, _______, KC_NLCK
),

[_MEDIA] = LAYOUT_planck_grid(
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_EJCT, KC_MUTE, KC_VOLD, KC_VOLU, _______,
   TG(_GAME),  KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, MUV_IN,
    CK_TOGG,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______,  KC_F13,  KC_F14,  KC_F15,  KC_F16, MUV_DE,
     MU_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MU_MOD
),


[_ADJUST] = LAYOUT_planck_grid(
    _______,   RESET,   DEBUG, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______,   MI_ON,  MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_GAME] = LAYOUT_planck_grid(
  KC_ESC, _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_ENT,
  _______, _______, _______, _______,  KC_SPC,  KC_SPC, _______, _______, _______,  _______, _______, _______
),

[_SUPER] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, SFTIT_U, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  SFTIT_L, SFTIT_D, SFTIT_R
)

};


uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _SHIFT:
        register_code(KC_LSFT);
        break;
    default:
        unregister_code(KC_LSFT);
        break;
    }
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
