#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _MQWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KC_LOWR = SAFE_RANGE,
  KC_RAIS
};

#define KC_MVLD LT(_MQWERTY, KC__VOLDOWN)
#define KC_MVLU LT(_MQWERTY, KC__VOLUP)
#define KC_MMPR LT(_MQWERTY, KC_MPRV)
#define KC_MMNX LT(_MQWERTY, KC_MNXT)
#define KC_MMUT LT(_MQWERTY, KC_MUTE)
#define KC_MMPL LT(_MQWERTY, KC_MPLY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// check this out https://git.kdb424.xyz/kdb424/qmk-firmware/src/branch/kdb424/keyboards/crkbd/keymaps/kdb424/keymap.c

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC/`|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | ENTR |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| VolDn |    | VolUp |------+------+------+------+------+------|
 * | LCTRL|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RCtl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ RSft \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 /* Keys not on base layer
  * -_ =+ `~ [{ ]} \|
  * arrows, nav cluster, numpad, media, adjust
  */

[_QWERTY] = LAYOUT( \
  KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
   KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,  \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MVLD,  KC_MVLU,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
                      KC_LALT, KC_LGUI, KC_LOWR, KC_SPC,           KC_RSFT, KC_RAIS, KC_RGUI, KC_RALT \
),

[_MQWERTY] = LAYOUT( \
  KC_BSPC,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,                     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC, \
   KC_ENT,  KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,                     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,  \
  KC_QUOT,  KC_H,   KC_J,    KC_K,    KC_L, KC_SCLN,                     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_LSFT, \
  KC_RCTL,  KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,  _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LCTL, \
                      KC_RALT, KC_RGUI, KC_RAIS, KC_RSFT,        KC_SPC, KC_LOWR, KC_LGUI, KC_LALT \
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |                    |  `   |      |      |  -   |  =   | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |                    |      |      |      |  [   |  ]   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |-------.    ,-------|      |      |      |      |      |  \   |
 * |------+------+------+------+------+------| Mute  |    | Play  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ RSft \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                    KC_GRV, XXXXXXX, XXXXXXX, KC_MINS,  KC_EQL,  KC_DEL, \
  _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, _______, \
  _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MMUT, KC_MMPL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |   /  |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Home |  Up  | End  | PgUp |                    |   *  |  4   |  5   |  6   |  ^   | PENT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down | Rght | PgDn |-------.    ,-------|   -  |  1   |  2   |  3   |  (   |  )   |
 * |------+------+------+------+------+------| Prev  |    | Next  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |  0   |  0   |  .   |  =   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ RSft \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      | MOVI |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSLS,   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______, \
  _______, XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                   KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_CIRC, KC_PENT, \
  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_LPRN, KC_RPRN, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MMPR, KC_MMNX, KC_PPLS,   KC_P0,   KC_P0, KC_PDOT, KC_PEQL, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | RESET| DEBUG|EEPROM|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ RSft \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  XXXXXXX,   RESET,   DEBUG, EEP_RST, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);
static void render_jabu(void) {
    static const char PROGMEM raw_jabu[] = {
        192, 32, 16,200,232,248,248,248,240,224,195,  7, 15, 31, 55, 15, 15, 31,  7, 63, 63,127,255,254,254, 56,  0,  0,  0,  0,  0,  0, 47, 80,160, 65, 67, 71, 71, 71, 35, 17, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 64, 62,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 56,124,254,254,248,240,224,240,252,248, 32,  0,  0,  0,128,192,254,255,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 15, 63,255,255,255,255,252,248,124, 62, 15,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,112,124, 63, 31, 15,199, 97, 56, 12,  0,192,112,240,248, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,112, 24, 14,  3,192,228,246,114, 51, 59, 31, 15,  7,  7,  4, 12, 56,224,192, 96, 48, 24,  8, 12,  4,  0,  0,  0,  0,128,192, 96, 56, 12,  2,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0, 32, 24, 44,  6,  3,  0,224, 48, 24, 12,  2,162,170,238,190,252,252,236,244,236,252,108,252,252,252, 92,252,236,252,252,188,220,
        0,  0,192,120, 14,131,144,216, 88, 77,109,124,126,223,255,255,246,127,254,127,247,190,255,255,127,239,253,255,253,127,223,255,  0,  0,127,227,225,241,240,248,120,120, 56,  0,  0,  0,  0,  3,  7, 13, 29, 63, 43, 59, 59, 57, 27, 31, 30, 14,  5,  7,130,195,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 26, 64,  0,  0,  0,  0,  0,  0,  0,  1,  3,112,240, 96,200,176,192,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 20, 64,  0,  0,  0,  0,  0,  0,  0,
        0,  2, 31, 47,117,254,239,245,222,199,176,152,204, 64, 88,120, 40, 32, 48, 16,  8, 16, 16, 16,  3, 16, 16, 16, 32, 70, 82,  0,  0,  0,  0,  0,  0,  0,  3,  2,  3,  1,  1, 14, 14,142,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 32, 32,  0,  0,  1,  3,  3,  3,  0, 24, 56, 56, 56,  0,  0, 48,112,112, 48,  0, 48,112,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  3,  0,  0, 28,  0,  0, 56,  0,  0, 32, 16,  0,112,  0,  0,  0,112,  0,  0, 96, 64, 32,
    };
    oled_write_raw_P(raw_jabu, sizeof(raw_jabu));
}

#define L_BASE 0
#define L_MIRROR (1 << 1)
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state_user(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_MIRROR:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mirror");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}


void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state_user(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    render_jabu();
  }
}
#endif // OLED_DRIVER_ENABLE

static int lower_counter = 0;
static uint16_t lower_timer;
static int raise_counter = 0;
static uint16_t raise_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
  // set_timelog();
  }

  switch (keycode) {
    case KC_LOWR:
      if (record->event.pressed) {
        lower_timer = timer_read();
        lower_counter += 1;
        layer_on(_LOWER);
      } else {
        if (lower_counter != 2) {
          layer_off(_LOWER);
        }
        layer_off(_RAISE);
      }
      return false;
    case KC_RAIS:
      if (record->event.pressed) {
        raise_timer = timer_read();
        raise_counter += 1;
        layer_on(_RAISE);
      } else {
        if (raise_counter != 2) {
          layer_off(_RAISE);
        }
        layer_off(_LOWER);
      }
      return false;
  }
  return true;
}

void matrix_scan_user(void) {
  if (timer_elapsed(lower_timer) > TAPPING_TERM) {
    lower_counter = 0;
    lower_timer = 0;
  }
  if (timer_elapsed(raise_timer) > TAPPING_TERM) {
    raise_counter = 0;
    raise_timer = 0;
  }
}
