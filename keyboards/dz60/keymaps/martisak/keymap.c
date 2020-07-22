#include QMK_KEYBOARD_H

// LAYERS
#define _QWERTY 0      // QWERTY layer
#define _QW _QWERTY

#define _FUNCTION 1    // Function layer
#define _FN _FUNCTION

#define _M 2

/* https://www.reddit.com/r/olkb/comments/ghjkvl/anyone_know_how_to_make_a_screenshot_key_for_mac/
 From u/TheMadTinker
 */

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Base QWERTY layer
  [_QWERTY] = LAYOUT_all(
      //       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_CPYP,
      KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC,  MO(_M),  KC_SPC,                    KC_RCMD, MO(_FN), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  // Hardware + function keys
  [_FUNCTION] = LAYOUT_all (
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_BRTG, _______, _______, _______, _______, _______, _______, _______,
      RESET,   _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______
  ),

  // Mac-layer
  [_M] = LAYOUT_all (
      RESET  , KC_SLCK, KC_PAUS, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_PSCR,
      _______, KC_CPYP, KC_CAPP, KC_CPYW, KC_CAPW, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
      _______, _______, _______,                   _______, _______, _______,                   _______, _______, KC_HOME, KC_PGDN, KC_END
  )

};
