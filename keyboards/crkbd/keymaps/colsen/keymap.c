#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
    CC_EMQM = SAFE_RANGE,
    CC_COSC,
    CC_PDCL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_NO , KC_Q         , KC_W         , KC_F    , KC_P    , KC_G      ,   KC_J    , KC_L    , KC_U    , KC_Y            , CC_EMQM         , KC_NO ,
    KC_NO , KC_A         , KC_R         , KC_S    , KC_T    , KC_D      ,   KC_H    , KC_N    , KC_E    , KC_I            , KC_O            , KC_NO ,
    KC_NO , LCTL_T(KC_Z) , LALT_T(KC_X) , KC_C    , KC_V    , KC_B      ,   KC_K    , KC_M    , CC_COSC , LALT_T(CC_PDCL) , LCTL_T(KC_QUOT) , KC_NO ,
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
    default:
      return true;
  }
}


const uint16_t PROGMEM n_space_combo[] = {KC_N, KC_SPC, COMBO_END};
const uint16_t PROGMEM a_r_s_t_combo[] = {KC_A, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM z_x_c_combo[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM x_c_v_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM r_t_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM a_s_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM t_c_combo[] = {KC_T, KC_C, COMBO_END};
const uint16_t PROGMEM f_t_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM a_r_s_combo[] = {KC_A, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM r_s_t_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM m_period_combo[] = {KC_M, CC_PDCL, COMBO_END};
const uint16_t PROGMEM l_y_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM n_u_combo[] = {KC_N, KC_U, COMBO_END};
const uint16_t PROGMEM n_coma_combo[] = {KC_N, CC_COSC, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM z_x_c_v_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM s_v_combo[] = {KC_S, KC_V, COMBO_END};
const uint16_t PROGMEM n_e_i_o_combo[] = {KC_N, KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM n_o_combo[] = {KC_N, KC_O, COMBO_END};
const uint16_t PROGMEM s_x_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM n_e_i_combo[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM e_i_o_combo[] = {KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM a_t_combo[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM d_b_combo[] = {KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM k_m_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM l_u_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM t_v_combo[] = {KC_T, KC_V, COMBO_END};
const uint16_t PROGMEM s_t_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM coma_period_combo[] = {CC_COSC, CC_PDCL, COMBO_END};
const uint16_t PROGMEM e_o_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM w_r_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM a_z_combo[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM r_x_combo[] = {KC_R, KC_X, COMBO_END};
const uint16_t PROGMEM s_c_combo[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM f_s_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM p_t_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM g_d_combo[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM j_h_combo[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM l_n_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM u_e_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM y_i_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM exclaim_o_combo[] = {CC_EMQM, KC_O, COMBO_END};
const uint16_t PROGMEM n_i_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM f_p_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM n_e_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM m_coma_combo[] = {KC_M, CC_COSC, COMBO_END};
const uint16_t PROGMEM m_coma_period_combo[] = {KC_M, CC_COSC, CC_PDCL, COMBO_END};
const uint16_t PROGMEM l_u_y_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM t_d_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM e_i_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM i_space_combo[] = {KC_I, KC_SPC, COMBO_END};
const uint16_t PROGMEM u_y_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM p_g_combo[] = {KC_P, KC_G, COMBO_END};

enum combos {
  CM_BTAB,
  CM_CLEAR_LINE,
  CM_COPY,
  CM_COPY_ALL,
  CM_CUT,
  CM_DEL_END,
  CM_DEL_HOME,
  CM_DEL_LINE_D,
  CM_DEL_LINE_U,
  CM_DEL_WORD_L,
  CM_DEL_WORD_R,
  CM_DOC_END,
  CM_DOC_START,
  CM_NEW_LINE_U,
  CM_NEW_LINE_D,
  CM_PASTE,
  CM_PASTE_ALL,
  CM_REDO,
  CM_SEL_ALL,
  CM_SEL_LINE,
  CM_UNDO,
  CM_WORD_L,
  CM_WORD_R,
  C_AT,
  C_LALT,
  C_BSPC,
  C_BRK,
  C_BRID,
  C_BRIU,
  C_LCTRL,
  C_DEL,
  C_DOWN,
  C_END,
  C_ESC,
  C_F1,
  C_F10,
  C_F11,
  C_F12,
  C_F2,
  C_F3,
  C_F4,
  C_F5,
  C_F6,
  C_F7,
  C_F8,
  C_F9,
  C_HOME,
  C_INS,
  C_LEFT,
  C_APP,
  C_PGDN,
  C_PGUP,
  C_MPLY,
  C_RGHT,
  C_TAB,
  C_UP,
  C_VOLU
};

combo_t key_combos[COMBO_COUNT] = {
  [CM_BTAB] = COMBO_ACTION(n_space_combo),
  [CM_CLEAR_LINE] = COMBO_ACTION(a_r_s_t_combo),
  [CM_COPY] = COMBO_ACTION(x_c_combo),
  [CM_COPY_ALL] = COMBO_ACTION(z_x_c_combo),
  [CM_CUT] = COMBO_ACTION(x_c_v_combo),
  [CM_DEL_END] = COMBO_ACTION(r_t_combo),
  [CM_DEL_HOME] = COMBO_ACTION(a_s_combo),
  [CM_DEL_LINE_D] = COMBO_ACTION(t_c_combo),
  [CM_DEL_LINE_U] = COMBO_ACTION(f_t_combo),
  [CM_DEL_WORD_L] = COMBO_ACTION(a_r_s_combo),
  [CM_DEL_WORD_R] = COMBO_ACTION(r_s_t_combo),
  [CM_DOC_END] = COMBO_ACTION(m_period_combo),
  [CM_DOC_START] = COMBO_ACTION(l_y_combo),
  [CM_NEW_LINE_U] = COMBO_ACTION(n_u_combo),
  [CM_NEW_LINE_D] = COMBO_ACTION(n_coma_combo),
  [CM_PASTE] = COMBO_ACTION(c_v_combo),
  [CM_PASTE_ALL] = COMBO_ACTION(z_x_c_v_combo),
  [CM_REDO] = COMBO_ACTION(s_v_combo),
  [CM_SEL_ALL] = COMBO_ACTION(n_e_i_o_combo),
  [CM_SEL_LINE] = COMBO_ACTION(n_o_combo),
  [CM_UNDO] = COMBO_ACTION(s_x_combo),
  [CM_WORD_L] = COMBO_ACTION(n_e_i_combo),
  [CM_WORD_R] = COMBO_ACTION(e_i_o_combo),
  [C_AT] = COMBO(a_t_combo, KC_AT),
  [C_LALT] = COMBO(d_b_combo, KC_LALT),
  [C_BSPC] = COMBO(r_s_combo, KC_BSPC),
  [C_BRK] = COMBO(q_w_combo, KC_BRK),
  [C_BRID] = COMBO(k_m_combo, KC_BRID),
  [C_BRIU] = COMBO(l_u_combo, KC_BRIU),
  [C_LCTRL] = COMBO(t_v_combo, KC_LCTRL),
  [C_DEL] = COMBO(s_t_combo, KC_DEL),
  [C_DOWN] = COMBO(coma_period_combo, KC_DOWN),
  [C_END] = COMBO(e_o_combo, KC_END),
  [C_ESC] = COMBO(w_f_combo, KC_ESC),
  [C_F1] = COMBO(w_r_combo, KC_F1),
  [C_F10] = COMBO(a_z_combo, KC_F10),
  [C_F11] = COMBO(r_x_combo, KC_F11),
  [C_F12] = COMBO(s_c_combo, KC_F12),
  [C_F2] = COMBO(f_s_combo, KC_F2),
  [C_F3] = COMBO(p_t_combo, KC_F3),
  [C_F4] = COMBO(g_d_combo, KC_F4),
  [C_F5] = COMBO(j_h_combo, KC_F5),
  [C_F6] = COMBO(l_n_combo, KC_F6),
  [C_F7] = COMBO(u_e_combo, KC_F7),
  [C_F8] = COMBO(y_i_combo, KC_F8),
  [C_F9] = COMBO(exclaim_o_combo, KC_F9),
  [C_HOME] = COMBO(n_i_combo, KC_HOME),
  [C_INS] = COMBO(f_p_combo, KC_INS),
  [C_LEFT] = COMBO(n_e_combo, KC_LEFT),
  [C_APP] = COMBO(m_coma_combo, KC_APP),
  [C_PGDN] = COMBO(m_coma_period_combo, KC_PGDN),
  [C_PGUP] = COMBO(l_u_y_combo, KC_PGUP),
  [C_MPLY] = COMBO(t_d_combo, KC_MPLY),
  [C_RGHT] = COMBO(e_i_combo, KC_RGHT),
  [C_TAB] = COMBO(i_space_combo, KC_TAB),
  [C_UP] = COMBO(u_y_combo, KC_UP),
  [C_VOLU] = COMBO(p_g_combo, KC_VOLU)
};

void process_combo_event(uint8_t combo_index, bool p) {
  switch(combo_index) {
    case CM_BTAB:       if (p) { SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT)); }  break;
    case CM_CLEAR_LINE: if (p) { SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) SS_TAP(X_DEL)); }  break;
    case CM_COPY:       if (p) { SEND_STRING(SS_LCTL("c")); }  break;
    case CM_COPY_ALL:   if (p) { SEND_STRING(SS_LCTL("ac")); }  break;
    case CM_CUT:        if (p) { SEND_STRING(SS_LCTL("x")); }  break;
    case CM_DEL_END:    if (p) { SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)SS_TAP(X_DEL)); }  break;
    case CM_DEL_HOME:   if (p) { SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_DEL)); }  break;
    case CM_DEL_LINE_D: if (p) { SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_DEL)SS_TAP(X_DEL));   }  break;
    case CM_DEL_LINE_U: if (p) { SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_BSPC)SS_TAP(X_BSPC)); }  break;
    case CM_DEL_WORD_L: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_BSPC)SS_UP(X_LCTL)); }  break;
    case CM_DEL_WORD_R: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_DEL)SS_UP(X_LCTL)); }  break;
    case CM_DOC_END:    if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL)); }  break;
    case CM_DOC_START:  if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL)); }  break;
    case CM_NEW_LINE_U: if (p) { SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_RGHT)); }  break;
    case CM_NEW_LINE_D: if (p) { SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT)); }  break;
    case CM_PASTE:      if (p) { SEND_STRING(SS_LCTL("v")); }  break;
    case CM_PASTE_ALL:  if (p) { SEND_STRING(SS_LCTL("av")); }  break;
    case CM_REDO:       if (p) { SEND_STRING(SS_LCTL("y")); }  break;
    case CM_SEL_ALL:    if (p) { SEND_STRING(SS_LCTL("a")); }  break;
    case CM_SEL_LINE:   if (p) { SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)); }  break;
    case CM_UNDO:       if (p) { SEND_STRING(SS_LCTL("z")); }  break;
    case CM_WORD_L:     if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LCTL)); }  break;
    case CM_WORD_R:     if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_UP(X_LCTL));  }  break;
  }
}
