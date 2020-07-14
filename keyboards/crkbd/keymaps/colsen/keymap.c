#include QMK_KEYBOARD_H

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_NO   , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G      ,   KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_NO   ,
    KC_NO   , KC_A    , KC_R    , KC_S    , KC_T    , KC_D      ,   KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_NO   ,
    KC_NO   , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B      ,   KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_QUOT , KC_NO   ,
                                  KC_LGUI , KC_LSFT , TT(1)     ,   MO(2)   , KC_SPC  , KC_ENT  
  ),

  [1] = LAYOUT(
    KC_TRNS , KC_0    , KC_1    , KC_2    , KC_3    , KC_4      ,   KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_TRNS ,
    KC_TRNS , KC_EQL  , KC_LCBR , KC_NO   , KC_RCBR , KC_DLR    ,   KC_HASH , KC_LPRN , KC_NO   , KC_RPRN , KC_MINS , KC_TRNS ,
    KC_TRNS , KC_SLSH , KC_LT   , KC_NO   , KC_GT   , KC_ASTR   ,   KC_NO   , KC_PERC , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
                                  KC_NO   , KC_NO   , KC_TRNS   ,   KC_TRNS , KC_TRNS , KC_TRNS 
  ),

  [2] = LAYOUT(
    KC_TRNS , KC_F10  , KC_F1   , KC_F2   , KC_F3   , KC_F4     ,   KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_TRNS ,
    KC_TRNS , KC_AT   , KC_F11  , KC_F12  , KC_NO   , KC_NO     ,   KC_VOLU , KC_LBRC , KC_NO   , KC_RBRC , KC_TILD , KC_TRNS ,
    KC_TRNS , KC_BSLS , KC_NO   , KC_CIRC , KC_INS  , KC_BRK    ,   KC_VOLD , KC_NO   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
                                  KC_TRNS , KC_TRNS , KC_NO     ,   KC_TRNS , KC_TRNS , KC_TRNS
  ),
  
};

enum combos {
  C_ESC,
  C_LEFT,
  C_RIGHT,
  C_UP,
  C_TAB,
  C_PAGE_UP,
  C_BACKSPACE,
  C_DELTE
};

const uint16_t PROGMEM fw_combo[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM en_combo[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ly_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM luy_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [C_ESC]  = COMBO(fw_combo, KC_ESC),
  [C_LEFT] = COMBO(en_combo, KC_LEFT),
  [C_UP] = COMBO(lu_combo, KC_UP),
  [C_TAB] = COMBO(uy_combo, KC_TAB),
  [C_PAGE_UP] = COMBO(luy_combo, KC_PGUP),
  [C_BACKSPACE] = COMBO(rs_combo, KC_BSPC),
  [C_DELTE] = COMBO(st_combo, KC_DEL),
};
