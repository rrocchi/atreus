#include "keymap_common.h"

/* This layout implements dvorak fully in the firmware. It will work
   on Linux machines where Xorg is set to use the 'Option "XkbLayout" "us"' 
   with the 'Option "XkbVariant" "altgr-intl"'.
   It won't work if the OS is already set for dvorak. For that use case, 
   see keymap_multidvorak.c. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, \
         KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, \
         KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, \
         KC_ESC, KC_TAB, KC_RALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,     \
         KC_SPC, KC_FN0, KC_MINS, KC_SLSH, KC_ENT),                     \
  /* 1: punctuation and numbers */
  KEYMAP(SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_3), SHIFT(KC_LBRC), SHIFT(KC_RBRC), \
		  KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8), \
		  SHIFT(KC_1), SHIFT(KC_2), KC_UP, KC_LBRC, KC_RBRC, \
		  KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_EQUAL), \
		  SHIFT(KC_4), KC_LEFT, KC_DOWN, KC_RIGHT, SHIFT(KC_7), \
		  KC_GRAVE, KC_1, KC_2, KC_3, KC_BSLS,    \
		  KC_FN1, SHIFT(KC_INS), KC_RALT, KC_LGUI, KC_LSFT, KC_LCTL, \
		  KC_LALT, KC_BSPC, KC_FN0, KC_DOT, KC_0, KC_EQUAL),

  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_CAPS, \
		  KC_PGUP, KC_F7, KC_F8, KC_F9, KC_F10, \
		  KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MENU, \
		  KC_PGDN, KC_F4, KC_F5, KC_F6, KC_F11,          \
		  KC_VOLU, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, \
		  KC_FN3, KC_F1, KC_F2, KC_F3, KC_F12,            \
		  KC_VOLD, KC_MUTE, KC_RALT, KC_LGUI, KC_LSFT, KC_LCTL, \
		  KC_LALT, KC_SPC, KC_FN2, KC_PSCREEN, KC_SLCK, KC_PAUSE)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
