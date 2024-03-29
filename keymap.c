#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CMD_ALT_LEFT,
  CMD_ALT_RIGHT
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

#define x KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |Lower |Space |Space |Raise | GUI  | Alt  | Ctrl |Shift |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   =  |      |  (   |   )  |   [  |   ]  |   -  |  Up  |   +  |   :  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  <   |   >  |      |      | Left | Down | Right|   ?  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_EQL,  x,       KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_MINS, KC_UP,   KC_PLUS, KC_COLN, KC_BSLS, \
  KC_DOT,  x,       x,       KC_LT,   KC_GT,   x,       x,       KC_LEFT, KC_DOWN, KC_RGHT, KC_QUES, KC_DQUO, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  | PUP  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  | Home | PDN  | End  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PGUP, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_PGDN, KC_END,  KC_QUES, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | TabL | MsU  | TabR |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |      | MsL  | MsD  | MsR  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Mute | VolU | VolD |      |  WhL | WhD  | WhU  | WhR  |      |SysRq |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, CMD_ALT_LEFT, KC_MS_U, CMD_ALT_RIGHT, _______, _______, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______, KC_MS_L, KC_MS_D, KC_MS_R, x,       _______, \
  _______, x,       KC_MUTE, KC_VOLD, KC_VOLU, x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CMD_ALT_LEFT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LGUI));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_LEFT));
      SEND_STRING(SS_UP(X_LALT));
      SEND_STRING(SS_UP(X_LGUI));
    } else {
    }
    return false;
  case CMD_ALT_RIGHT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LGUI));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_RIGHT));
      SEND_STRING(SS_UP(X_LALT));
      SEND_STRING(SS_UP(X_LGUI));
    } else {
    }
    return false;
  }
  return true;
}
