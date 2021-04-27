#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _MOVIE,
  _ADJUST,
};

enum custom_keycodes {
  KC_MOVI = SAFE_RANGE
};

#define KC_RAIS MO(_RAISE)
#define KC_LOWR MO(_LOWER)
#define KC_BASE TO(_QWERTY)

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
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_VOLD,  KC_VOLU,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
                      KC_LALT, KC_LGUI, KC_LOWR, KC_SPC,           KC_RSFT, KC_RAIS, KC_RGUI, KC_RALT \
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
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |   /  |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Home |  Up  | End  | PgUp |      |                    |   *  |  4   |  5   |  6   |  ^   | PENT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down | Rght | PgDn |      |-------.    ,-------|   -  |  1   |  2   |  3   |  (   |  )   |
 * |------+------+------+------+------+------| Prev  |    | Next  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |  0   |  0   |  .   |  =   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ RSft \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      | MOVI |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSLS,   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______, \
  _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX,                   KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_CIRC, KC_PENT, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,                   KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_LPRN, KC_RPRN, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_PPLS,   KC_P0,   KC_P0, KC_PDOT, KC_PEQL, _______, \
                             _______, _______, _______, _______, _______, _______, _______, KC_MOVI \
),
/* Movie (maybe just make this put arrow keys on top. trouble is jupiter hell needs the dot too)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Exit |      |      |      |      |      |                    |      |      |      | Mute | VolDn| VolUp|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      | Left | Down | Right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ RSft \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MOVIE] = LAYOUT( \
   KC_BASE, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, \
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,   KC_UP, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, \
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
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
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
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

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t movi_tap_timer;
  static bool movi_inverting;

  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    if (keycode == KC_MOVI) {
      movi_tap_timer = timer_read();
      movi_inverting = true;
      register_mods(MOD_BIT(KC_RALT));
      return false;
    }
    // set_timelog();
  } else {
    if (keycode == KC_MOVI) {
      unregister_mods(MOD_BIT(KC_LALT));
      if (timer_elapsed(movi_tap_timer) < TAPPING_TERM && movi_inverting) {
        layer_invert(_MOVIE);
      }
      return false;
    }
  }

  movi_inverting = false;
  return true;
}
