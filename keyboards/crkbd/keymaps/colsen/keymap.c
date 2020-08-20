#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
    CC_DOT = SAFE_RANGE,
    CC_COMA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_NO , KC_Z    , KC_W    , KC_F    , KC_P    , KC_G      ,   KC_J    , KC_L    , KC_U    , KC_Y    , KC_Q    , KC_NO ,
    KC_NO , KC_A    , KC_R    , KC_S    , KC_T    , KC_D      ,   KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_NO ,
    KC_NO , KC_LCTL , KC_LALT , KC_C    , KC_V    , KC_B      ,   KC_K    , KC_M    , CC_COMA , CC_DOT  , KC_X    , KC_NO ,
                                KC_LGUI , KC_LSFT , TT(1)     ,   KC_ENT  , KC_SPC  , KC_QUOT
  ),

  [1] = LAYOUT(
    KC_NO , KC_0    , KC_1    , KC_2    , KC_3    , KC_4      ,   KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_NO ,
    KC_NO , KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN , KC_DLR    ,   KC_HASH , KC_SLSH , KC_EQL  , KC_ASTR , KC_PLUS , KC_NO ,
    KC_NO , _______ , _______ , KC_LBRC , KC_RBRC , KC_PERC   ,   KC_LT   , KC_GT   , _______ , _______ , KC_TILD , KC_NO ,
                                _______ , KC_NO   , _______   ,   _______ , _______ , KC_GRV 
  ),
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CC_COMA: // Coma / question mark
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SLSH);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_SLSH);
        unregister_code(KC_COMM);
      }
      return false;
    case CC_DOT: // Period / exclamation mark
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_1);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_1);
        unregister_code(KC_DOT);
      }
      return false;
    default:
      return true;
  }
}

// Begin paste from spreadsheet `def 1`
const uint16_t PROGMEM a_alt_1_combo[] = {KC_A, KC_LALT, COMBO_END};
const uint16_t PROGMEM a_alt_2_combo[] = {KC_LCBR, KC_LALT, COMBO_END};
const uint16_t PROGMEM a_r_1_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM a_r_2_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM alt_c_1_combo[] = {KC_LALT, KC_C, COMBO_END};
const uint16_t PROGMEM alt_c_2_combo[] = {KC_LALT, KC_LBRC, COMBO_END};
const uint16_t PROGMEM alt_c_v_1_combo[] = {KC_LALT, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM alt_c_v_2_combo[] = {KC_LALT, KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM alt_v_1_combo[] = {KC_LALT, KC_V, COMBO_END};
const uint16_t PROGMEM alt_v_2_combo[] = {KC_LALT, KC_RBRC, COMBO_END};
const uint16_t PROGMEM c_v_1_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_v_2_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM coma_dot_1_combo[] = {CC_COMA, CC_DOT, COMBO_END};
const uint16_t PROGMEM coma_dot_2_combo[] = {CC_COMA, CC_DOT, COMBO_END};
const uint16_t PROGMEM coma_dot_x_1_combo[] = {CC_COMA, CC_DOT, KC_X, COMBO_END};
const uint16_t PROGMEM coma_dot_x_2_combo[] = {CC_COMA, CC_DOT, KC_TILD, COMBO_END};
const uint16_t PROGMEM d_b_1_combo[] = {KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM d_b_2_combo[] = {KC_DLR, KC_PERC, COMBO_END};
const uint16_t PROGMEM e_dot_1_combo[] = {KC_E, CC_DOT, COMBO_END};
const uint16_t PROGMEM e_dot_2_combo[] = {KC_EQL, CC_DOT, COMBO_END};
const uint16_t PROGMEM e_i_1_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM e_i_2_combo[] = {KC_EQL, KC_ASTR, COMBO_END};
const uint16_t PROGMEM e_m_1_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM e_m_2_combo[] = {KC_EQL, KC_GT, COMBO_END};
const uint16_t PROGMEM f_p_1_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM f_p_2_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM f_s_1_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM f_s_2_combo[] = {KC_2, KC_LPRN, COMBO_END};
const uint16_t PROGMEM f_t_1_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM f_t_2_combo[] = {KC_2, KC_RPRN, COMBO_END};
const uint16_t PROGMEM g_d_1_combo[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM g_d_2_combo[] = {KC_4, KC_DLR, COMBO_END};
const uint16_t PROGMEM h_k_1_combo[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM h_k_2_combo[] = {KC_HASH, KC_LT, COMBO_END};
const uint16_t PROGMEM i_o_1_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM i_o_2_combo[] = {KC_ASTR, KC_PLUS, COMBO_END};
const uint16_t PROGMEM j_h_1_combo[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM j_h_2_combo[] = {KC_5, KC_HASH, COMBO_END};
const uint16_t PROGMEM l_h_1_combo[] = {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM l_h_2_combo[] = {KC_6, KC_HASH, COMBO_END};
const uint16_t PROGMEM l_n_1_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM l_n_2_combo[] = {KC_6, KC_SLSH, COMBO_END};
const uint16_t PROGMEM l_u_1_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM l_u_2_combo[] = {KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM m_coma_1_combo[] = {KC_M, CC_COMA, COMBO_END};
const uint16_t PROGMEM m_coma_2_combo[] = {KC_GT, CC_COMA, COMBO_END};
const uint16_t PROGMEM m_coma_dot_1_combo[] = {KC_M, CC_COMA, CC_DOT, COMBO_END};
const uint16_t PROGMEM m_coma_dot_2_combo[] = {KC_GT, CC_COMA, CC_DOT, COMBO_END};
const uint16_t PROGMEM m_dot_1_combo[] = {KC_M, CC_DOT, COMBO_END};
const uint16_t PROGMEM m_dot_2_combo[] = {KC_GT, CC_DOT, COMBO_END};
const uint16_t PROGMEM n_e_1_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM n_e_2_combo[] = {KC_SLSH, KC_EQL, COMBO_END};
const uint16_t PROGMEM n_e_i_1_combo[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM n_e_i_2_combo[] = {KC_SLSH, KC_EQL, KC_ASTR, COMBO_END};
const uint16_t PROGMEM n_k_1_combo[] = {KC_N, KC_K, COMBO_END};
const uint16_t PROGMEM n_k_2_combo[] = {KC_SLSH, KC_LT, COMBO_END};
const uint16_t PROGMEM n_m_1_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM n_m_2_combo[] = {KC_SLSH, KC_GT, COMBO_END};
const uint16_t PROGMEM p_d_1_combo[] = {KC_P, KC_D, COMBO_END};
const uint16_t PROGMEM p_d_2_combo[] = {KC_3, KC_DLR, COMBO_END};
const uint16_t PROGMEM p_g_1_combo[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM p_g_2_combo[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM p_t_1_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM p_t_2_combo[] = {KC_3, KC_RPRN, COMBO_END};
const uint16_t PROGMEM q_o_1_combo[] = {KC_Q, KC_O, COMBO_END};
const uint16_t PROGMEM q_o_2_combo[] = {KC_9, KC_PLUS, COMBO_END};
const uint16_t PROGMEM r_ctrl_1_combo[] = {KC_R, KC_LCTL, COMBO_END};
const uint16_t PROGMEM r_ctrl_2_combo[] = {KC_RCBR, KC_LCTL, COMBO_END};
const uint16_t PROGMEM r_f_1_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM r_f_2_combo[] = {KC_RCBR, KC_2, COMBO_END};
const uint16_t PROGMEM r_s_1_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM r_s_2_combo[] = {KC_RCBR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM r_s_t_1_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM r_s_t_2_combo[] = {KC_RCBR, KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM r_t_1_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM r_t_2_combo[] = {KC_RCBR, KC_RPRN, COMBO_END};
const uint16_t PROGMEM s_alt_1_combo[] = {KC_S, KC_LALT, COMBO_END};
const uint16_t PROGMEM s_alt_2_combo[] = {KC_LPRN, KC_LALT, COMBO_END};
const uint16_t PROGMEM s_c_1_combo[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM s_c_2_combo[] = {KC_LPRN, KC_LBRC, COMBO_END};
const uint16_t PROGMEM s_t_1_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM s_t_2_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM s_v_1_combo[] = {KC_S, KC_V, COMBO_END};
const uint16_t PROGMEM s_v_2_combo[] = {KC_LPRN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM t_b_1_combo[] = {KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM t_b_2_combo[] = {KC_RPRN, KC_PERC, COMBO_END};
const uint16_t PROGMEM t_d_1_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM t_d_2_combo[] = {KC_RPRN, KC_DLR, COMBO_END};
const uint16_t PROGMEM t_v_1_combo[] = {KC_T, KC_V, COMBO_END};
const uint16_t PROGMEM t_v_2_combo[] = {KC_RPRN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM u_e_1_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM u_e_2_combo[] = {KC_7, KC_EQL, COMBO_END};
const uint16_t PROGMEM u_I_1_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM u_I_2_combo[] = {KC_7, KC_ASTR, COMBO_END};
const uint16_t PROGMEM u_n_1_combo[] = {KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM u_n_2_combo[] = {KC_7, KC_SLSH, COMBO_END};
const uint16_t PROGMEM u_y_1_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM u_y_2_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM v_b_1_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM v_b_2_combo[] = {KC_RBRC, KC_PERC, COMBO_END};
const uint16_t PROGMEM w_a_1_combo[] = {KC_W, KC_A, COMBO_END};
const uint16_t PROGMEM w_a_2_combo[] = {KC_1, KC_LCBR, COMBO_END};
const uint16_t PROGMEM w_f_1_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM w_f_2_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM w_p_1_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM w_p_2_combo[] = {KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM w_r_1_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM w_r_2_combo[] = {KC_1, KC_RCBR, COMBO_END};
const uint16_t PROGMEM y_i_1_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM y_i_2_combo[] = {KC_8, KC_ASTR, COMBO_END};
const uint16_t PROGMEM z_a_1_combo[] = {KC_Z, KC_A, COMBO_END};
const uint16_t PROGMEM z_a_2_combo[] = {KC_0, KC_LCBR, COMBO_END};
const uint16_t PROGMEM z_w_1_combo[] = {KC_Z, KC_W, COMBO_END};
const uint16_t PROGMEM z_w_2_combo[] = {KC_0, KC_1, COMBO_END};
// End paste from spreadsheet `def 1`

enum combos {
  // Begin paste from spreadsheet `def 2`
  COMBO_a_alt_1,
  COMBO_a_alt_2,
  COMBO_a_r_1,
  COMBO_a_r_2,
  COMBO_alt_c_1,
  COMBO_alt_c_2,
  COMBO_alt_c_v_1,
  COMBO_alt_c_v_2,
  COMBO_alt_v_1,
  COMBO_alt_v_2,
  COMBO_c_v_1,
  COMBO_c_v_2,
  COMBO_coma_dot_1,
  COMBO_coma_dot_2,
  COMBO_coma_dot_x_1,
  COMBO_coma_dot_x_2,
  COMBO_d_b_1,
  COMBO_d_b_2,
  COMBO_e_dot_1,
  COMBO_e_dot_2,
  COMBO_e_i_1,
  COMBO_e_i_2,
  COMBO_e_m_1,
  COMBO_e_m_2,
  COMBO_f_p_1,
  COMBO_f_p_2,
  COMBO_f_s_1,
  COMBO_f_s_2,
  COMBO_f_t_1,
  COMBO_f_t_2,
  COMBO_g_d_1,
  COMBO_g_d_2,
  COMBO_h_k_1,
  COMBO_h_k_2,
  COMBO_i_o_1,
  COMBO_i_o_2,
  COMBO_j_h_1,
  COMBO_j_h_2,
  COMBO_l_h_1,
  COMBO_l_h_2,
  COMBO_l_n_1,
  COMBO_l_n_2,
  COMBO_l_u_1,
  COMBO_l_u_2,
  COMBO_m_coma_1,
  COMBO_m_coma_2,
  COMBO_m_coma_dot_1,
  COMBO_m_coma_dot_2,
  COMBO_m_dot_1,
  COMBO_m_dot_2,
  COMBO_n_e_1,
  COMBO_n_e_2,
  COMBO_n_e_i_1,
  COMBO_n_e_i_2,
  COMBO_n_k_1,
  COMBO_n_k_2,
  COMBO_n_m_1,
  COMBO_n_m_2,
  COMBO_p_d_1,
  COMBO_p_d_2,
  COMBO_p_g_1,
  COMBO_p_g_2,
  COMBO_p_t_1,
  COMBO_p_t_2,
  COMBO_q_o_1,
  COMBO_q_o_2,
  COMBO_r_ctrl_1,
  COMBO_r_ctrl_2,
  COMBO_r_f_1,
  COMBO_r_f_2,
  COMBO_r_s_1,
  COMBO_r_s_2,
  COMBO_r_s_t_1,
  COMBO_r_s_t_2,
  COMBO_r_t_1,
  COMBO_r_t_2,
  COMBO_s_alt_1,
  COMBO_s_alt_2,
  COMBO_s_c_1,
  COMBO_s_c_2,
  COMBO_s_t_1,
  COMBO_s_t_2,
  COMBO_s_v_1,
  COMBO_s_v_2,
  COMBO_t_b_1,
  COMBO_t_b_2,
  COMBO_t_d_1,
  COMBO_t_d_2,
  COMBO_t_v_1,
  COMBO_t_v_2,
  COMBO_u_e_1,
  COMBO_u_e_2,
  COMBO_u_I_1,
  COMBO_u_I_2,
  COMBO_u_n_1,
  COMBO_u_n_2,
  COMBO_u_y_1,
  COMBO_u_y_2,
  COMBO_v_b_1,
  COMBO_v_b_2,
  COMBO_w_a_1,
  COMBO_w_a_2,
  COMBO_w_f_1,
  COMBO_w_f_2,
  COMBO_w_p_1,
  COMBO_w_p_2,
  COMBO_w_r_1,
  COMBO_w_r_2,
  COMBO_y_i_1,
  COMBO_y_i_2,
  COMBO_z_a_1,
  COMBO_z_a_2,
  COMBO_z_w_1,
  COMBO_z_w_2,
  // End paste from spreadsheet `def 2`
};

combo_t key_combos[COMBO_COUNT] = {
  // Begin paste from spreadsheet `def 3`
  [COMBO_a_alt_1] = COMBO(a_alt_1_combo, DYN_REC_START1),
  [COMBO_a_alt_2] = COMBO(a_alt_2_combo, DYN_REC_START1),
  [COMBO_a_r_1] = COMBO(a_r_1_combo, KC_BSPC),
  [COMBO_a_r_2] = COMBO(a_r_2_combo, KC_BSPC),
  [COMBO_alt_c_1] = COMBO(alt_c_1_combo, KC_HOME),
  [COMBO_alt_c_2] = COMBO(alt_c_2_combo, KC_HOME),
  [COMBO_alt_c_v_1] = COMBO_ACTION(alt_c_v_1_combo),
  [COMBO_alt_c_v_2] = COMBO_ACTION(alt_c_v_2_combo),
  [COMBO_alt_v_1] = COMBO(alt_v_1_combo, KC_SCLN),
  [COMBO_alt_v_2] = COMBO(alt_v_2_combo, KC_SCLN),
  [COMBO_c_v_1] = COMBO(c_v_1_combo, KC_END),
  [COMBO_c_v_2] = COMBO(c_v_2_combo, KC_END),
  [COMBO_coma_dot_1] = COMBO(coma_dot_1_combo, KC_RGHT),
  [COMBO_coma_dot_2] = COMBO(coma_dot_2_combo, KC_RGHT),
  [COMBO_coma_dot_x_1] = COMBO_ACTION(coma_dot_x_1_combo),
  [COMBO_coma_dot_x_2] = COMBO_ACTION(coma_dot_x_2_combo),
  [COMBO_d_b_1] = COMBO(d_b_1_combo, KC_PIPE),
  [COMBO_d_b_2] = COMBO(d_b_2_combo, KC_PIPE),
  [COMBO_e_dot_1] = COMBO(e_dot_1_combo, KC_DOWN),
  [COMBO_e_dot_2] = COMBO(e_dot_2_combo, KC_DOWN),
  [COMBO_e_i_1] = COMBO(e_i_1_combo, KC_MINS),
  [COMBO_e_i_2] = COMBO(e_i_2_combo, KC_MINS),
  [COMBO_e_m_1] = COMBO(e_m_1_combo, KC_UP),
  [COMBO_e_m_2] = COMBO(e_m_2_combo, KC_UP),
  [COMBO_f_p_1] = COMBO_ACTION(f_p_1_combo),
  [COMBO_f_p_2] = COMBO_ACTION(f_p_2_combo),
  [COMBO_f_s_1] = COMBO(f_s_1_combo, KC_F2),
  [COMBO_f_s_2] = COMBO(f_s_2_combo, KC_F2),
  [COMBO_f_t_1] = COMBO_ACTION(f_t_1_combo),
  [COMBO_f_t_2] = COMBO_ACTION(f_t_2_combo),
  [COMBO_g_d_1] = COMBO(g_d_1_combo, KC_F4),
  [COMBO_g_d_2] = COMBO(g_d_2_combo, KC_F4),
  [COMBO_h_k_1] = COMBO(h_k_1_combo, KC_AT),
  [COMBO_h_k_2] = COMBO(h_k_2_combo, KC_AT),
  [COMBO_i_o_1] = COMBO(i_o_1_combo, KC_MINS),
  [COMBO_i_o_2] = COMBO(i_o_2_combo, KC_MINS),
  [COMBO_j_h_1] = COMBO(j_h_1_combo, KC_F5),
  [COMBO_j_h_2] = COMBO(j_h_2_combo, KC_F5),
  [COMBO_l_h_1] = COMBO_ACTION(l_h_1_combo),
  [COMBO_l_h_2] = COMBO_ACTION(l_h_2_combo),
  [COMBO_l_n_1] = COMBO(l_n_1_combo, KC_F6),
  [COMBO_l_n_2] = COMBO(l_n_2_combo, KC_F6),
  [COMBO_l_u_1] = COMBO(l_u_1_combo, KC_INS),
  [COMBO_l_u_2] = COMBO(l_u_2_combo, KC_INS),
  [COMBO_m_coma_1] = COMBO(m_coma_1_combo, KC_LEFT),
  [COMBO_m_coma_2] = COMBO(m_coma_2_combo, KC_LEFT),
  [COMBO_m_coma_dot_1] = COMBO_ACTION(m_coma_dot_1_combo),
  [COMBO_m_coma_dot_2] = COMBO_ACTION(m_coma_dot_2_combo),
  [COMBO_m_dot_1] = COMBO(m_dot_1_combo, KC_APP),
  [COMBO_m_dot_2] = COMBO(m_dot_2_combo, KC_APP),
  [COMBO_n_e_1] = COMBO(n_e_1_combo, KC_BSPC),
  [COMBO_n_e_2] = COMBO(n_e_2_combo, KC_BSPC),
  [COMBO_n_e_i_1] = COMBO_ACTION(n_e_i_1_combo),
  [COMBO_n_e_i_2] = COMBO_ACTION(n_e_i_2_combo),
  [COMBO_n_k_1] = COMBO_ACTION(n_k_1_combo),
  [COMBO_n_k_2] = COMBO_ACTION(n_k_2_combo),
  [COMBO_n_m_1] = COMBO(n_m_1_combo, KC_UNDS),
  [COMBO_n_m_2] = COMBO(n_m_2_combo, KC_UNDS),
  [COMBO_p_d_1] = COMBO(p_d_1_combo, KC_BSLASH),
  [COMBO_p_d_2] = COMBO(p_d_2_combo, KC_BSLASH),
  [COMBO_p_g_1] = COMBO_ACTION(p_g_1_combo),
  [COMBO_p_g_2] = COMBO_ACTION(p_g_2_combo),
  [COMBO_p_t_1] = COMBO(p_t_1_combo, KC_F3),
  [COMBO_p_t_2] = COMBO(p_t_2_combo, KC_F3),
  [COMBO_q_o_1] = COMBO(q_o_1_combo, KC_F9),
  [COMBO_q_o_2] = COMBO(q_o_2_combo, KC_F9),
  [COMBO_r_ctrl_1] = COMBO(r_ctrl_1_combo, DYN_MACRO_PLAY1),
  [COMBO_r_ctrl_2] = COMBO(r_ctrl_2_combo, DYN_MACRO_PLAY1),
  [COMBO_r_f_1] = COMBO_ACTION(r_f_1_combo),
  [COMBO_r_f_2] = COMBO_ACTION(r_f_2_combo),
  [COMBO_r_s_1] = COMBO(r_s_1_combo, KC_ESC),
  [COMBO_r_s_2] = COMBO(r_s_2_combo, KC_ESC),
  [COMBO_r_s_t_1] = COMBO_ACTION(r_s_t_1_combo),
  [COMBO_r_s_t_2] = COMBO_ACTION(r_s_t_2_combo),
  [COMBO_r_t_1] = COMBO_ACTION(r_t_1_combo),
  [COMBO_r_t_2] = COMBO_ACTION(r_t_2_combo),
  [COMBO_s_alt_1] = COMBO_ACTION(s_alt_1_combo),
  [COMBO_s_alt_2] = COMBO_ACTION(s_alt_2_combo),
  [COMBO_s_c_1] = COMBO(s_c_1_combo, KC_F12),
  [COMBO_s_c_2] = COMBO(s_c_2_combo, KC_F12),
  [COMBO_s_t_1] = COMBO(s_t_1_combo, KC_DEL),
  [COMBO_s_t_2] = COMBO(s_t_2_combo, KC_DEL),
  [COMBO_s_v_1] = COMBO(s_v_1_combo, KC_TAB),
  [COMBO_s_v_2] = COMBO(s_v_2_combo, KC_TAB),
  [COMBO_t_b_1] = COMBO(t_b_1_combo, KC_ENT),
  [COMBO_t_b_2] = COMBO(t_b_2_combo, KC_ENT),
  [COMBO_t_d_1] = COMBO_ACTION(t_d_1_combo),
  [COMBO_t_d_2] = COMBO_ACTION(t_d_2_combo),
  [COMBO_t_v_1] = COMBO(t_v_1_combo, KC_AMPR),
  [COMBO_t_v_2] = COMBO(t_v_2_combo, KC_AMPR),
  [COMBO_u_e_1] = COMBO(u_e_1_combo, KC_F7),
  [COMBO_u_e_2] = COMBO(u_e_2_combo, KC_F7),
  [COMBO_u_I_1] = COMBO(u_I_1_combo, KC_PGDN),
  [COMBO_u_I_2] = COMBO(u_I_2_combo, KC_PGDN),
  [COMBO_u_n_1] = COMBO(u_n_1_combo, KC_PGUP),
  [COMBO_u_n_2] = COMBO(u_n_2_combo, KC_PGUP),
  [COMBO_u_y_1] = COMBO(u_y_1_combo, KC_COLN),
  [COMBO_u_y_2] = COMBO(u_y_2_combo, KC_COLN),
  [COMBO_v_b_1] = COMBO(v_b_1_combo, KC_SPC),
  [COMBO_v_b_2] = COMBO(v_b_2_combo, KC_SPC),
  [COMBO_w_a_1] = COMBO(w_a_1_combo, KC_F11),
  [COMBO_w_a_2] = COMBO(w_a_2_combo, KC_F11),
  [COMBO_w_f_1] = COMBO_ACTION(w_f_1_combo),
  [COMBO_w_f_2] = COMBO_ACTION(w_f_2_combo),
  [COMBO_w_p_1] = COMBO(w_p_1_combo, KC_CIRC),
  [COMBO_w_p_2] = COMBO(w_p_2_combo, KC_CIRC),
  [COMBO_w_r_1] = COMBO(w_r_1_combo, KC_F1),
  [COMBO_w_r_2] = COMBO(w_r_2_combo, KC_F1),
  [COMBO_y_i_1] = COMBO(y_i_1_combo, KC_F8),
  [COMBO_y_i_2] = COMBO(y_i_2_combo, KC_F8),
  [COMBO_z_a_1] = COMBO(z_a_1_combo, KC_F10),
  [COMBO_z_a_2] = COMBO(z_a_2_combo, KC_F10),
  [COMBO_z_w_1] = COMBO_ACTION(z_w_1_combo),
  [COMBO_z_w_2] = COMBO_ACTION(z_w_2_combo),
  // End paste from spreadsheet `def 3`
};

void process_combo_event(uint8_t combo_index, bool p) {
  switch(combo_index) {
    // Begin paste from spreadsheet `def 4`
    case COMBO_alt_c_v_1: if (p) {SEND_STRING(SS_LCTL("a")SS_TAP(X_DEL));}  break;
    case COMBO_alt_c_v_2: if (p) {SEND_STRING(SS_LCTL("a")SS_TAP(X_DEL));}  break;
    case COMBO_coma_dot_x_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;
    case COMBO_coma_dot_x_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;
    case COMBO_f_p_1: if (p) {SEND_STRING(SS_LCTL("a"));}  break;
    case COMBO_f_p_2: if (p) {SEND_STRING(SS_LCTL("a"));}  break;
    case COMBO_f_t_1: if (p) {SEND_STRING(SS_LCTL("v"));}  break;
    case COMBO_f_t_2: if (p) {SEND_STRING(SS_LCTL("v"));}  break;
    case COMBO_l_h_1: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_UP));}  break;
    case COMBO_l_h_2: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_UP));}  break;
    case COMBO_m_coma_dot_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;
    case COMBO_m_coma_dot_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;
    case COMBO_n_e_i_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;
    case COMBO_n_e_i_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;
    case COMBO_n_k_1: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));}  break;
    case COMBO_n_k_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));}  break;
    case COMBO_p_g_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL));}  break;
    case COMBO_p_g_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL));}  break;
    case COMBO_r_f_1: if (p) {SEND_STRING(SS_LCTL("c"));}  break;
    case COMBO_r_f_2: if (p) {SEND_STRING(SS_LCTL("c"));}  break;
    case COMBO_r_s_t_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;
    case COMBO_r_s_t_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;
    case COMBO_r_t_1: if (p) {SEND_STRING(SS_LCTL("x"));}  break;
    case COMBO_r_t_2: if (p) {SEND_STRING(SS_LCTL("x"));}  break;
    case COMBO_s_alt_1: if (p) {SEND_STRING(SS_LCTL("s"));}  break;
    case COMBO_s_alt_2: if (p) {SEND_STRING(SS_LCTL("s"));}  break;
    case COMBO_t_d_1: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT));}  break;
    case COMBO_t_d_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT));}  break;
    case COMBO_w_f_1: if (p) {SEND_STRING(SS_LCTL("z"));}  break;
    case COMBO_w_f_2: if (p) {SEND_STRING(SS_LCTL("z"));}  break;
    case COMBO_z_w_1: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL));}  break;
    case COMBO_z_w_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL));}  break;
    // End paste from spreadsheet `def 4`
  }
}

