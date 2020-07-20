#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
    CC_EMQM = SAFE_RANGE,
    CC_COSC,
    CC_PDCL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_NO , KC_Q , KC_W , KC_F , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , CC_EMQM , KC_NO ,
    KC_NO , KC_A , KC_R , KC_S , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_NO ,
    KC_NO , KC_Z , KC_X , KC_C , KC_V    , KC_B    , KC_K    , KC_M    , CC_COSC , CC_PDCL , KC_QUOT , KC_NO ,
                                 KC_LGUI , KC_LSFT , TT(1)   , KC_UNDS , KC_SPC  , KC_ENT  
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

const uint16_t PROGMEM k_m_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM dot_quot_combo[] = {CC_PDCL, KC_QUOT, COMBO_END};
const uint16_t PROGMEM y_excl_combo[] = {KC_Y, CC_EMQM, COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM e_dot_combo[] = {KC_E, CC_PDCL, COMBO_END};
const uint16_t PROGMEM f_s_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM l_n_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM p_t_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM u_e_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM r_s_t_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM n_e_i_combo[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM r_t_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM e_o_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM s_v_combo[] = {KC_S, KC_V, COMBO_END};
const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM w_a_combo[] = {KC_W, KC_A, COMBO_END};
const uint16_t PROGMEM q_r_combo[] = {KC_Q, KC_R, COMBO_END};
const uint16_t PROGMEM w_s_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM f_t_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM f_r_combo[] = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM p_s_combo[] = {KC_P, KC_S, COMBO_END};
const uint16_t PROGMEM g_t_combo[] = {KC_G, KC_T, COMBO_END};
const uint16_t PROGMEM j_l_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM l_h_combo[] = {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM u_n_combo[] = {KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM y_e_combo[] = {KC_Y, KC_E, COMBO_END};
const uint16_t PROGMEM excl_i_combo[] = {CC_EMQM, KC_I, COMBO_END};
const uint16_t PROGMEM a_s_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM n_i_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM f_p_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM n_e_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM e_m_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM s_t_d_combo[] = {KC_S, KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM x_c_v_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM m_coma_dot_combo[] = {KC_M, CC_COSC, CC_PDCL, COMBO_END};
const uint16_t PROGMEM w_f_p_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM l_u_y_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM s_t_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM e_i_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM i_coma_combo[] = {KC_I, CC_COSC, COMBO_END};
const uint16_t PROGMEM d_b_combo[] = {KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM n_m_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM r_f_t_combo[] = {KC_R, KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM n_u_i_combo[] = {KC_N, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM v_b_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM p_g_combo[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM t_v_combo[] = {KC_T, KC_V, COMBO_END};
const uint16_t PROGMEM h_k_combo[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM h_o_combo[] = {KC_H, KC_O, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM m_coma_combo[] = {KC_M, CC_COSC, COMBO_END};
const uint16_t PROGMEM l_u_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM w_r_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM j_h_combo[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM g_d_combo[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM y_i_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM x_v_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM w_p_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM m_coma_dot_quot_combo[] = {KC_M, CC_COSC, CC_PDCL, KC_QUOT, COMBO_END};
const uint16_t PROGMEM l_u_y_excl_combo[] = {KC_L, KC_U, KC_Y, CC_EMQM, COMBO_END};
const uint16_t PROGMEM m_dot_combo[] = {KC_M, CC_PDCL, COMBO_END};
const uint16_t PROGMEM l_y_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM coma_dot_combo[] = {CC_COSC, CC_PDCL, COMBO_END};
const uint16_t PROGMEM u_y_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM n_e_i_o_combo[] = {KC_N, KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM n_o_combo[] = {KC_N, KC_O, COMBO_END};
const uint16_t PROGMEM r_z_combo[] = {KC_R, KC_Z, COMBO_END};
const uint16_t PROGMEM a_r_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM h_n_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM t_d_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM i_o_combo[] = {KC_I, KC_O, COMBO_END};

enum combos {
  C_APP,
  C_BRID,
  C_BRIU,
  C_BRK,
  C_BSLASH,
  C_BSPC_1,
  C_BSPC_2,
  C_DEL_1,
  C_DEL_2,
  C_DOWN_1,
  C_DOWN_2,
  C_END_1,
  C_END_2,
  C_ENTER,
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
  C_HOME_1,
  C_HOME_2,
  C_INS,
  C_LEFT_1,
  C_LEFT,
  C_MINS,
  C_MPLY,
  C_PGDN_1,
  C_PGDN_2,
  C_PGUP_1,
  C_PGUP_2,
  C_RGHT_1,
  C_RGHT_2,
  C_SLASH,
  C_TAB_1,
  C_TAB_2,
  C_UP_1,
  C_UP_2,
  C_VOL_DOWN,
  C_VOL_UP,
  CM_BTAB_1,
  CM_BTAB_2,
  CM_CLEAR_LINE,
  CM_COPY,
  CM_CUT,
  CM_DEL_LINE_D,
  CM_DEL_LINE_U,
  CM_DEL_WORD_L_1,
  CM_DEL_WORD_L_2,
  CM_DEL_WORD_R_1,
  CM_DEL_WORD_R_2,
  CM_DOC_END,
  CM_DOC_START,
  CM_DUP_LINE_D,
  CM_DUP_LINE_u,
  CM_JOIN_LINES_D,
  CM_JOIN_LINES_U,
  CM_NEW_LINE_D,
  CM_NEW_LINE_U,
  CM_PASTE,
  CM_SEL_ALL,
  CM_SEL_LINE,
  CM_UNDO,
  CM_WORD_L_1,
  CM_WORD_L_2,
  CM_WORD_R_1,
  CM_WORD_R_2,
};

combo_t key_combos[COMBO_COUNT] = {
  [C_APP] = COMBO(k_m_combo, KC_APP),
  [C_BRID] = COMBO(dot_quot_combo, KC_BRID),
  [C_BRIU] = COMBO(y_excl_combo, KC_BRIU),
  [C_BRK] = COMBO(q_w_combo, KC_BRK),
  [C_BSLASH] = COMBO(e_dot_combo, KC_BSLASH),
  [C_BSPC_1] = COMBO(f_s_combo, KC_BSPC),
  [C_BSPC_2] = COMBO(l_n_combo, KC_BSPC),
  [C_DEL_1] = COMBO(p_t_combo, KC_DEL),
  [C_DEL_2] = COMBO(u_e_combo, KC_DEL),
  [C_DOWN_1] = COMBO(r_s_t_combo, KC_DOWN),
  [C_DOWN_2] = COMBO(n_e_i_combo, KC_DOWN),
  [C_END_1] = COMBO(r_t_combo, KC_END),
  [C_END_2] = COMBO(e_o_combo, KC_END),
  [C_ENTER] = COMBO(s_v_combo, KC_ENT),
  [C_ESC] = COMBO(w_f_combo, KC_ESC),
  [C_F1] = COMBO(w_a_combo, KC_F1),
  [C_F10] = COMBO(q_r_combo, KC_F10),
  [C_F11] = COMBO(w_s_combo, KC_F11),
  [C_F12] = COMBO(f_t_combo, KC_F12),
  [C_F2] = COMBO(f_r_combo, KC_F2),
  [C_F3] = COMBO(p_s_combo, KC_F3),
  [C_F4] = COMBO(g_t_combo, KC_F4),
  [C_F5] = COMBO(j_l_combo, KC_F5),
  [C_F6] = COMBO(l_h_combo, KC_F6),
  [C_F7] = COMBO(u_n_combo, KC_F7),
  [C_F8] = COMBO(y_e_combo, KC_F8),
  [C_F9] = COMBO(excl_i_combo, KC_F9),
  [C_HOME_1] = COMBO(a_s_combo, KC_HOME),
  [C_HOME_2] = COMBO(n_i_combo, KC_HOME),
  [C_INS] = COMBO(f_p_combo, KC_INS),
  [C_LEFT_1] = COMBO(r_s_combo, KC_LEFT),
  [C_LEFT] = COMBO(n_e_combo, KC_LEFT),
  [C_MINS] = COMBO(e_m_combo, KC_MINS),
  [C_MPLY] = COMBO(s_t_d_combo, KC_MPLY),
  [C_PGDN_1] = COMBO(x_c_v_combo, KC_PGDN),
  [C_PGDN_2] = COMBO(m_coma_dot_combo, KC_PGDN),
  [C_PGUP_1] = COMBO(w_f_p_combo, KC_PGUP),
  [C_PGUP_2] = COMBO(l_u_y_combo, KC_PGUP),
  [C_RGHT_1] = COMBO(s_t_combo, KC_RGHT),
  [C_RGHT_2] = COMBO(e_i_combo, KC_RGHT),
  [C_SLASH] = COMBO(i_coma_combo, KC_SLASH),
  [C_TAB_1] = COMBO(d_b_combo, KC_TAB),
  [C_TAB_2] = COMBO(n_m_combo, KC_TAB),
  [C_UP_1] = COMBO(r_f_t_combo, KC_UP),
  [C_UP_2] = COMBO(n_u_i_combo, KC_UP),
  [C_VOL_DOWN] = COMBO(v_b_combo, KC_VOLD),
  [C_VOL_UP] = COMBO(p_g_combo, KC_VOLU),
  [CM_BTAB_1] = COMBO_ACTION(t_v_combo),
  [CM_BTAB_2] = COMBO_ACTION(h_k_combo),
  [CM_CLEAR_LINE] = COMBO_ACTION(h_o_combo),
  [CM_COPY] = COMBO_ACTION(x_c_combo),
  [CM_CUT] = COMBO_ACTION(z_x_combo),
  [CM_DEL_LINE_D] = COMBO_ACTION(m_coma_combo),
  [CM_DEL_LINE_U] = COMBO_ACTION(l_u_combo),
  [CM_DEL_WORD_L_1] = COMBO_ACTION(w_r_combo),
  [CM_DEL_WORD_L_2] = COMBO_ACTION(j_h_combo),
  [CM_DEL_WORD_R_1] = COMBO_ACTION(g_d_combo),
  [CM_DEL_WORD_R_2] = COMBO_ACTION(y_i_combo),
  [CM_DOC_END] = COMBO_ACTION(x_v_combo),
  [CM_DOC_START] = COMBO_ACTION(w_p_combo),
  [CM_DUP_LINE_D] = COMBO_ACTION(m_coma_dot_quot_combo),
  [CM_DUP_LINE_u] = COMBO_ACTION(l_u_y_excl_combo),
  [CM_JOIN_LINES_D] = COMBO_ACTION(m_dot_combo),
  [CM_JOIN_LINES_U] = COMBO_ACTION(l_y_combo),
  [CM_NEW_LINE_D] = COMBO_ACTION(coma_dot_combo),
  [CM_NEW_LINE_U] = COMBO_ACTION(u_y_combo),
  [CM_PASTE] = COMBO_ACTION(c_v_combo),
  [CM_SEL_ALL] = COMBO_ACTION(n_e_i_o_combo),
  [CM_SEL_LINE] = COMBO_ACTION(n_o_combo),
  [CM_UNDO] = COMBO_ACTION(r_z_combo),
  [CM_WORD_L_1] = COMBO_ACTION(a_r_combo),
  [CM_WORD_L_2] = COMBO_ACTION(h_n_combo),
  [CM_WORD_R_1] = COMBO_ACTION(t_d_combo),
  [CM_WORD_R_2] = COMBO_ACTION(i_o_combo),

};

void process_combo_event(uint8_t combo_index, bool p) {
  switch(combo_index) {
    case CM_BTAB_1: if (p) { SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT)); }  break;
    case CM_BTAB_2: if (p) { SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT)); }  break;
    case CM_CLEAR_LINE: if (p) { SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) SS_TAP(X_DEL)); }  break;
    case CM_COPY: if (p) { SEND_STRING(SS_LCTL("c")); }  break;
    case CM_CUT: if (p) { SEND_STRING(SS_LCTL("x")); }  break;
    case CM_DEL_LINE_D: if (p) { SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_DEL)SS_TAP(X_DEL)); }  break;
    case CM_DEL_LINE_U: if (p) { SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_BSPC)SS_TAP(X_BSPC)); }  break;
    case CM_DEL_WORD_L_1: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_BSPC)SS_UP(X_LCTL)); }  break;
    case CM_DEL_WORD_L_2: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_BSPC)SS_UP(X_LCTL)); }  break;
    case CM_DEL_WORD_R_1: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_DEL)SS_UP(X_LCTL)); }  break;
    case CM_DEL_WORD_R_2: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_DEL)SS_UP(X_LCTL)); }  break;
    case CM_DOC_END: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL)); }  break;
    case CM_DOC_START: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL)); }  break;
    case CM_DUP_LINE_D: if (p) { SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_LCTL("c")SS_TAP(X_END)SS_TAP(X_ENT)SS_LCTL("v")); }  break;
    case CM_DUP_LINE_u: if (p) { SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_LCTL("c")SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_LEFT)SS_LCTL("v")); }  break;
    case CM_JOIN_LINES_D: if (p) { SEND_STRING(SS_TAP(X_END)SS_TAP(X_DEL)); }  break;
    case CM_JOIN_LINES_U: if (p) { SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_BSPC)); }  break;
    case CM_NEW_LINE_D: if (p) { SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT)); }  break;
    case CM_NEW_LINE_U: if (p) { SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_RGHT)); }  break;
    case CM_PASTE: if (p) { SEND_STRING(SS_LCTL("v")); }  break;
    case CM_SEL_ALL: if (p) { SEND_STRING(SS_LCTL("a")); }  break;
    case CM_SEL_LINE: if (p) { SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)); }  break;
    case CM_UNDO: if (p) { SEND_STRING(SS_LCTL("z")); }  break;
    case CM_WORD_L_1: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LCTL)); }  break;
    case CM_WORD_L_2: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LCTL)); }  break;
    case CM_WORD_R_1: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_UP(X_LCTL)); }  break;
    case CM_WORD_R_2: if (p) { SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_UP(X_LCTL)); }  break;
  }
}
