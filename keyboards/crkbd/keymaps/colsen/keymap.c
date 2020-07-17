#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
    CC_EMQM = SAFE_RANGE,
    CC_COSC,
    CC_PDCL,

    CC_DWL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_NO   , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G      ,   KC_J    , KC_L    , KC_U    , KC_Y    , CC_EMQM , KC_NO   ,
    KC_LCTL , KC_A    , KC_R    , KC_S    , KC_T    , KC_D      ,   KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_LCTL ,
    KC_LALT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B      ,   KC_K    , KC_M    , CC_COSC , CC_PDCL , KC_QUOT , KC_LALT ,
                                  KC_LGUI , KC_LSFT , TT(1)     ,   KC_UNDS , KC_SPC  , KC_ENT  
  ),

  [1] = LAYOUT(
    _______ , KC_0    , KC_1    , KC_2    , KC_3    , KC_4      ,   KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , _______ ,
    _______ , KC_EQL  , KC_LCBR , KC_NO   , KC_RCBR , KC_DLR    ,   KC_HASH , KC_LPRN , KC_NO   , KC_RPRN , KC_MINS , _______ ,
    _______ , KC_SLSH , KC_LT   , KC_NO   , KC_GT   , KC_ASTR   ,   KC_NO   , KC_PERC , _______ , _______ , _______ , _______ ,
                                  KC_NO   , KC_NO   , _______   ,   _______ , _______ , _______ 
  ),
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CC_EMQM: // Exclamation mark / question mark
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SLSH);
        } else {
          uint8_t current_mods = get_mods();
          set_mods(current_mods | MOD_LSFT); // Turn on shift
          register_code(KC_1);
          set_mods(current_mods); // Turn shift back off again
        }
      } else {
        unregister_code(KC_1);
        unregister_code(KC_SLSH);
      }
      return false;
    case CC_COSC: // Coma / semicolon
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          uint8_t current_mods = get_mods();
          set_mods(current_mods & ~(MOD_LSFT | MOD_RSFT)); // Turn off shift
          register_code(KC_SCLN);
          set_mods(current_mods); // Turn shift back on again
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_SCLN);
        unregister_code(KC_COMM);
      }
      return false;
    case CC_PDCL: // Period / colon
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SCLN);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_SCLN);
        unregister_code(KC_DOT);
      }
      return false;
    case CC_DWL:
      if (record->event.pressed){
        //SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_BSPC) SS_UP(X_LCTL));
        SEND_STRING("x");
      }
      return false;
    default:
      return true;
  }
}

enum combos {
  C_ESC,
  C_LEFT,
  C_RIGHT,
  C_UP,
  C_TAB,
  C_PAGE_UP,
  C_BACKSPACE,
  C_DELTE,
  C_DWL
};

const uint16_t PROGMEM fw_combo[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM ars_combo[] = {KC_A, KC_R, KC_S, COMBO_END};

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
  [C_DWL] = COMBO(vb_combo, CC_DWL)
};
