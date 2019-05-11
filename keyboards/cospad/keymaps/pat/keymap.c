#include QMK_KEYBOARD_H
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _______ KC_TRNS


enum cospad_layers {
      // _PS,
      _QLL,
      _QLR,
      _NLL,
      _NLR,
      _NAV
};

enum custom_keycodes {
      PS_SELECT = SAFE_RANGE,
      PS_DESELECT,
      PS_SEL_INV,
      PS_NEW_LAYER,
      PS_SAVE,
      PS_TRANSFORM,
      PS_UNDO,
      PS_REDO
};
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
            case PS_SELECT:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL("a"));
                  } 
                  break;
            case PS_DESELECT:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL("d"));
                  }
                  break;
            case PS_SEL_INV:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL(SS_LSFT("i")));
                  }
                  break;
            case PS_NEW_LAYER:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL(SS_LSFT("n")));
                  }
                  break;
            case PS_SAVE:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL("s"));
                  }
                  break;
            case PS_UNDO:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_Z))));
                  }
                  break;
            case PS_REDO:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_Z))));
                  }
                  break;
            case PS_TRANSFORM:
                  if (record->event.pressed) {
                        SEND_STRING(SS_LCTRL("t"));
                  }
                  break;
      }
      return true;
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
[_PS] = LAYOUT_ortho_6x4(
      PS_DESELECT, PS_SELECT, PS_SEL_INV, PS_SAVE,\
      PS_NEW_LAYER, KC_E, KC_B, KC_RBRC,\
      KC_M, KC_C, KC_V, KC_LBRC,\
      PS_UNDO, PS_REDO, PS_TRANSFORM, KC_L,\
      KC_LSFT, KC_Z, KC_X, KC_D,\
      KC_LCTRL, KC_R, KC_LALT, KC_SPACE),
*/
/* Keymap _QWERTY/LOWER: Additional layer to access more
   * ,-----------------------.
   * |LCTRL|LSFT | TAB | GESC|      t
   * |-----|-----|-----|-----|
   * | LGUI|  Z  |  A  |  Q  |
   * |-----|-----|-----|-----|
   * |LALT |  X  |  S  |  W  |
   * |-----|-----|-----|-----|
   * |BSPC |  C  |  D  |  E  |
   * |-----|-----|-----|-----|
   * |ENTER|  V  |  F  |  R  |
   * |-----|-----|-----|-----|
   * |SPACE|  B  |  G  |  T  |
   * `-----------------------'
   * ,-----------------------.
   * |     |  N  |  H  |  Y  |
   * |-----|-----|-----|-----|
   * |     |  M  |  J  |  U  |
   * |-----|-----|-----|-----|
   * |     |  ,< |  K  |  I  |
   * |-----|-----|-----|-----|
   * |LALT |  .> |  L  |  O  |
   * |-----|-----|-----|-----|
   * |_SYMB|  /? |  ;: |  P  |
   * |-----|-----|-----|-----|
   * |     |     |  '" |BSPC |
   * `-----------------------'
*/

[_QLL] = LAYOUT_ortho_6x4(
      KC_LCTRL, KC_LSFT, LT(_NAV, KC_TAB), KC_GESC,\
      KC_LGUI, KC_Z, KC_A, KC_Q,\
      KC_LALT, KC_X, KC_S, KC_W,\
      MO(_NLL), KC_C, KC_D, KC_E,\
      MO(_QLL), KC_V, KC_F, KC_R,\
      LT(_QLR, KC_SPACE), KC_B, KC_G, KC_T),

[_QLR] = LAYOUT_ortho_6x4(
      KC_CAPS, MT(MOD_LSFT, KC_ENTER), KC_QUOT, KC_BSPC,\
      _______, KC_SLSH, KC_SCLN, KC_P,\
      _______, KC_DOT, KC_L, KC_O,\
      _______, KC_COMM, KC_K, KC_I,\
      _______, KC_M, KC_J, KC_U, \
      _______, KC_N, KC_H, KC_Y),

/*
   * ,-----------------------.
   * |     |  F1 | \|  |     |
   * |-----|-----|-----|-----|
   * |     |  F2 | ]}  |  1  |
   * |-----|-----|-----|-----|
   * |     |  F3 | [{  |  2  |
   * |-----|-----|-----|-----|
   * |     |  F4 |     |  3  |
   * |-----|-----|-----|-----|
   * |     |  F5 |     |  4  |
   * |-----|-----|-----|-----|
   * |     |  F6 |     |  5  |
   * `-----------------------'
   * ,-----------------------.
   * |     | F12 |     | DEL |
   * |-----|-----|-----|-----|
   * |     | F11 |  =+ |  0  |
   * |-----|-----|-----|-----|
   * |     | F10 |  -_ |  9  |
   * |-----|-----|-----|-----|
   * |     | F9  |     |  8  |
   * |-----|-----|-----|-----|
   * |     | F8  |     |  7  |
   * |-----|-----|-----|-----|
   * |     | F7  |     |  6  |
   * `-----------------------'
*/
[_NLL] = LAYOUT_ortho_6x4(
      _______, KC_F1, KC_BSLS, _______, \
      _______, KC_F2, KC_RBRC, KC_1,\
      _______, KC_F3, KC_LBRC, KC_2,\
      _______, KC_F4, KC_EQL, KC_3,\
      _______, KC_F5, KC_MINS, KC_4,\
      MO(_NLR), KC_F6, _______, KC_5),

[_NLR] = LAYOUT_ortho_6x4(
      _______, KC_F12, _______, KC_DEL,\
      _______, KC_F11, KC_EQL, KC_0,\
      _______, KC_F10, KC_MINS, KC_9,\
      _______, KC_F9, _______, KC_8,\
      _______, KC_F8, _______, KC_7,\
      _______, KC_F7, _______, KC_6),

/*
   * ,-----------------------.
   * |RCTL | RSFT|     |     |
   * |-----|-----|-----|-----|
   * |     | LEFT| PGUP|     |
   * |-----|-----|-----|-----|
   * |     | DN  | PGDN|     |
   * |-----|-----|-----|-----|
   * |     | UP  | HOME|     |
   * |-----|-----|-----|-----|
   * |     | RGHT| END |     |
   * |-----|-----|-----|-----|
   * |     |     |     |     |
   * `-----------------------'
*/

[_NAV] =LAYOUT_ortho_6x4(
      _______, KC_RSFT, _______, MAGIC_NO_GUI, \
      _______, _______, KC_LEFT, KC_PGDN, \
      _______, KC_HOME, KC_DOWN, KC_UP, \
      _______, KC_END, KC_RIGHT, KC_PGUP, \
      KC_RCTL, _______, _______, _______, \
      KC_SPACE, _______, _______, MAGIC_UNNO_GUI),
};