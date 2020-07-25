#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
    CC_EMQM = SAFE_RANGE,
    CC_COSC,
    CC_PDCL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_NO   , KC_Q , KC_W , KC_F , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , CC_EMQM , KC_NO   ,
    KC_LCTL , KC_A , KC_R , KC_S , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_LCTL ,
    KC_LALT , KC_Z , KC_X , KC_C , KC_V    , KC_B    , KC_K    , KC_M    , CC_COSC , CC_PDCL , KC_QUOT , KC_LALT ,
                                   KC_LGUI , KC_LSFT , TT(1)   , KC_ENT  , KC_SPC  , KC_UNDS
  ),

  [1] = LAYOUT(
    _______ , KC_0    , KC_1    , KC_2    , KC_3    , KC_4      ,   KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , _______ ,
    _______ , KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN , KC_DLR    ,   KC_HASH , KC_MINS , KC_EQL  , KC_ASTR , KC_PLUS , _______ ,
    _______ , KC_LT   , KC_GT   , KC_LBRC , KC_RBRC , KC_PERC   ,   KC_CIRC , KC_BSLS , KC_SLSH , _______ , KC_GRV  , _______ ,
                                  KC_AMPR , KC_PIPE , _______   ,   KC_TILD , _______ , _______ 
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

// Begin paste from spreadsheet `def 1`
const uint16_t PROGMEM k_m_combo[] = {KC_K, KC_M, COMBO_END}; const uint16_t PROGMEM k_m_2_combo[] = {KC_CIRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM dot_quot_combo[] = {CC_PDCL, KC_QUOT, COMBO_END}; const uint16_t PROGMEM dot_quot_2_combo[] = {CC_PDCL, KC_GRV, COMBO_END};
const uint16_t PROGMEM y_excl_combo[] = {KC_Y, CC_EMQM, COMBO_END}; const uint16_t PROGMEM y_excl_2_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END}; const uint16_t PROGMEM q_w_2_combo[] = {KC_0, KC_1, COMBO_END};
const uint16_t PROGMEM e_dot_combo[] = {KC_E, CC_PDCL, COMBO_END}; const uint16_t PROGMEM e_dot_2_combo[] = {KC_EQL, CC_PDCL, COMBO_END};
const uint16_t PROGMEM f_s_combo[] = {KC_F, KC_S, COMBO_END}; const uint16_t PROGMEM f_s_2_combo[] = {KC_2, KC_LPRN, COMBO_END};
const uint16_t PROGMEM l_n_combo[] = {KC_L, KC_N, COMBO_END}; const uint16_t PROGMEM l_n_2_combo[] = {KC_6, KC_MINS, COMBO_END};
const uint16_t PROGMEM p_t_combo[] = {KC_P, KC_T, COMBO_END}; const uint16_t PROGMEM p_t_2_combo[] = {KC_3, KC_RPRN, COMBO_END};
const uint16_t PROGMEM u_e_combo[] = {KC_U, KC_E, COMBO_END}; const uint16_t PROGMEM u_e_2_combo[] = {KC_7, KC_EQL, COMBO_END};
const uint16_t PROGMEM r_s_t_combo[] = {KC_R, KC_S, KC_T, COMBO_END}; const uint16_t PROGMEM r_s_t_2_combo[] = {KC_RCBR, KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM n_e_i_combo[] = {KC_N, KC_E, KC_I, COMBO_END}; const uint16_t PROGMEM n_e_i_2_combo[] = {KC_MINS, KC_EQL, KC_ASTR, COMBO_END};
const uint16_t PROGMEM r_t_combo[] = {KC_R, KC_T, COMBO_END}; const uint16_t PROGMEM r_t_2_combo[] = {KC_RCBR, KC_RPRN, COMBO_END};
const uint16_t PROGMEM e_o_combo[] = {KC_E, KC_O, COMBO_END}; const uint16_t PROGMEM e_o_2_combo[] = {KC_EQL, KC_PLUS, COMBO_END};
const uint16_t PROGMEM s_v_combo[] = {KC_S, KC_V, COMBO_END}; const uint16_t PROGMEM s_v_2_combo[] = {KC_LPRN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END}; const uint16_t PROGMEM w_f_2_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM w_a_combo[] = {KC_W, KC_A, COMBO_END}; const uint16_t PROGMEM w_a_2_combo[] = {KC_1, KC_LCBR, COMBO_END};
const uint16_t PROGMEM q_r_combo[] = {KC_Q, KC_R, COMBO_END}; const uint16_t PROGMEM q_r_2_combo[] = {KC_0, KC_RCBR, COMBO_END};
const uint16_t PROGMEM w_s_combo[] = {KC_W, KC_S, COMBO_END}; const uint16_t PROGMEM w_s_2_combo[] = {KC_1, KC_LPRN, COMBO_END};
const uint16_t PROGMEM f_t_combo[] = {KC_F, KC_T, COMBO_END}; const uint16_t PROGMEM f_t_2_combo[] = {KC_2, KC_RPRN, COMBO_END};
const uint16_t PROGMEM f_r_combo[] = {KC_F, KC_R, COMBO_END}; const uint16_t PROGMEM f_r_2_combo[] = {KC_2, KC_RCBR, COMBO_END};
const uint16_t PROGMEM p_s_combo[] = {KC_P, KC_S, COMBO_END}; const uint16_t PROGMEM p_s_2_combo[] = {KC_3, KC_LPRN, COMBO_END};
const uint16_t PROGMEM g_t_combo[] = {KC_G, KC_T, COMBO_END}; const uint16_t PROGMEM g_t_2_combo[] = {KC_4, KC_RPRN, COMBO_END};
const uint16_t PROGMEM j_l_combo[] = {KC_J, KC_L, COMBO_END}; const uint16_t PROGMEM j_l_2_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM l_h_combo[] = {KC_L, KC_H, COMBO_END}; const uint16_t PROGMEM l_h_2_combo[] = {KC_6, KC_HASH, COMBO_END};
const uint16_t PROGMEM u_n_combo[] = {KC_U, KC_N, COMBO_END}; const uint16_t PROGMEM u_n_2_combo[] = {KC_7, KC_MINS, COMBO_END};
const uint16_t PROGMEM y_e_combo[] = {KC_Y, KC_E, COMBO_END}; const uint16_t PROGMEM y_e_2_combo[] = {KC_8, KC_EQL, COMBO_END};
const uint16_t PROGMEM excl_i_combo[] = {CC_EMQM, KC_I, COMBO_END}; const uint16_t PROGMEM excl_i_2_combo[] = {KC_9, KC_ASTR, COMBO_END};
const uint16_t PROGMEM a_s_combo[] = {KC_A, KC_S, COMBO_END}; const uint16_t PROGMEM a_s_2_combo[] = {KC_LCBR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM n_i_combo[] = {KC_N, KC_I, COMBO_END}; const uint16_t PROGMEM n_i_2_combo[] = {KC_MINS, KC_ASTR, COMBO_END};
const uint16_t PROGMEM f_p_combo[] = {KC_F, KC_P, COMBO_END}; const uint16_t PROGMEM f_p_2_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END}; const uint16_t PROGMEM r_s_2_combo[] = {KC_RCBR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM n_e_combo[] = {KC_N, KC_E, COMBO_END}; const uint16_t PROGMEM n_e_2_combo[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM e_m_combo[] = {KC_E, KC_M, COMBO_END}; const uint16_t PROGMEM e_m_2_combo[] = {KC_EQL, KC_BSLS, COMBO_END};
const uint16_t PROGMEM s_t_d_combo[] = {KC_S, KC_T, KC_D, COMBO_END}; const uint16_t PROGMEM s_t_d_2_combo[] = {KC_LPRN, KC_RPRN, KC_DLR, COMBO_END};
const uint16_t PROGMEM x_c_v_combo[] = {KC_X, KC_C, KC_V, COMBO_END}; const uint16_t PROGMEM x_c_v_2_combo[] = {KC_GT, KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM m_coma_dot_combo[] = {KC_M, CC_COSC, CC_PDCL, COMBO_END}; const uint16_t PROGMEM m_coma_dot_2_combo[] = {KC_BSLS, KC_SLSH, CC_PDCL, COMBO_END};
const uint16_t PROGMEM w_f_p_combo[] = {KC_W, KC_F, KC_P, COMBO_END}; const uint16_t PROGMEM w_f_p_2_combo[] = {KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM l_u_y_combo[] = {KC_L, KC_U, KC_Y, COMBO_END}; const uint16_t PROGMEM l_u_y_2_combo[] = {KC_6, KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM s_t_combo[] = {KC_S, KC_T, COMBO_END}; const uint16_t PROGMEM s_t_2_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM e_i_combo[] = {KC_E, KC_I, COMBO_END}; const uint16_t PROGMEM e_i_2_combo[] = {KC_EQL, KC_ASTR, COMBO_END};
const uint16_t PROGMEM i_coma_combo[] = {KC_I, CC_COSC, COMBO_END}; const uint16_t PROGMEM i_coma_2_combo[] = {KC_ASTR, KC_SLSH, COMBO_END};
const uint16_t PROGMEM d_b_combo[] = {KC_D, KC_B, COMBO_END}; const uint16_t PROGMEM d_b_2_combo[] = {KC_DLR, KC_PERC, COMBO_END};
const uint16_t PROGMEM n_m_combo[] = {KC_N, KC_M, COMBO_END}; const uint16_t PROGMEM n_m_2_combo[] = {KC_MINS, KC_BSLS, COMBO_END};
const uint16_t PROGMEM r_f_t_combo[] = {KC_R, KC_F, KC_T, COMBO_END}; const uint16_t PROGMEM r_f_t_2_combo[] = {KC_RCBR, KC_2, KC_RPRN, COMBO_END};
const uint16_t PROGMEM n_u_i_combo[] = {KC_N, KC_U, KC_I, COMBO_END}; const uint16_t PROGMEM n_u_i_2_combo[] = {KC_MINS, KC_7, KC_ASTR, COMBO_END};
const uint16_t PROGMEM v_b_combo[] = {KC_V, KC_B, COMBO_END}; const uint16_t PROGMEM v_b_2_combo[] = {KC_RBRC, KC_PERC, COMBO_END};
const uint16_t PROGMEM p_g_combo[] = {KC_P, KC_G, COMBO_END}; const uint16_t PROGMEM p_g_2_combo[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM t_v_combo[] = {KC_T, KC_V, COMBO_END}; const uint16_t PROGMEM t_v_2_combo[] = {KC_RPRN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM h_k_combo[] = {KC_H, KC_K, COMBO_END}; const uint16_t PROGMEM h_k_2_combo[] = {KC_HASH, KC_CIRC, COMBO_END};
const uint16_t PROGMEM h_o_combo[] = {KC_H, KC_O, COMBO_END}; const uint16_t PROGMEM h_o_2_combo[] = {KC_HASH, KC_PLUS, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END}; const uint16_t PROGMEM x_c_2_combo[] = {KC_GT, KC_LBRC, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END}; const uint16_t PROGMEM z_x_2_combo[] = {KC_LT, KC_GT, COMBO_END};
const uint16_t PROGMEM m_coma_combo[] = {KC_M, CC_COSC, COMBO_END}; const uint16_t PROGMEM m_coma_2_combo[] = {KC_BSLS, KC_SLSH, COMBO_END};
const uint16_t PROGMEM l_u_combo[] = {KC_L, KC_U, COMBO_END}; const uint16_t PROGMEM l_u_2_combo[] = {KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM w_r_combo[] = {KC_W, KC_R, COMBO_END}; const uint16_t PROGMEM w_r_2_combo[] = {KC_1, KC_RCBR, COMBO_END};
const uint16_t PROGMEM j_h_combo[] = {KC_J, KC_H, COMBO_END}; const uint16_t PROGMEM j_h_2_combo[] = {KC_5, KC_HASH, COMBO_END};
const uint16_t PROGMEM g_d_combo[] = {KC_G, KC_D, COMBO_END}; const uint16_t PROGMEM g_d_2_combo[] = {KC_4, KC_DLR, COMBO_END};
const uint16_t PROGMEM y_i_combo[] = {KC_Y, KC_I, COMBO_END}; const uint16_t PROGMEM y_i_2_combo[] = {KC_8, KC_ASTR, COMBO_END};
const uint16_t PROGMEM x_v_combo[] = {KC_X, KC_V, COMBO_END}; const uint16_t PROGMEM x_v_2_combo[] = {KC_GT, KC_RBRC, COMBO_END};
const uint16_t PROGMEM w_p_combo[] = {KC_W, KC_P, COMBO_END}; const uint16_t PROGMEM w_p_2_combo[] = {KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM m_coma_dot_quot_combo[] = {KC_M, CC_COSC, CC_PDCL, KC_QUOT, COMBO_END}; const uint16_t PROGMEM m_coma_dot_quot_2_combo[] = {KC_BSLS, KC_SLSH, CC_PDCL, KC_GRV, COMBO_END};
const uint16_t PROGMEM l_u_y_excl_combo[] = {KC_L, KC_U, KC_Y, CC_EMQM, COMBO_END}; const uint16_t PROGMEM l_u_y_excl_2_combo[] = {KC_6, KC_7, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM m_dot_combo[] = {KC_M, CC_PDCL, COMBO_END}; const uint16_t PROGMEM m_dot_2_combo[] = {KC_BSLS, CC_PDCL, COMBO_END};
const uint16_t PROGMEM l_y_combo[] = {KC_L, KC_Y, COMBO_END}; const uint16_t PROGMEM l_y_2_combo[] = {KC_6, KC_8, COMBO_END};
const uint16_t PROGMEM coma_dot_combo[] = {CC_COSC, CC_PDCL, COMBO_END}; const uint16_t PROGMEM coma_dot_2_combo[] = {KC_SLSH, CC_PDCL, COMBO_END};
const uint16_t PROGMEM u_y_combo[] = {KC_U, KC_Y, COMBO_END}; const uint16_t PROGMEM u_y_2_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END}; const uint16_t PROGMEM c_v_2_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM n_e_i_o_combo[] = {KC_N, KC_E, KC_I, KC_O, COMBO_END}; const uint16_t PROGMEM n_e_i_o_2_combo[] = {KC_MINS, KC_EQL, KC_ASTR, KC_PLUS, COMBO_END};
const uint16_t PROGMEM n_o_combo[] = {KC_N, KC_O, COMBO_END}; const uint16_t PROGMEM n_o_2_combo[] = {KC_MINS, KC_PLUS, COMBO_END};
const uint16_t PROGMEM r_z_combo[] = {KC_R, KC_Z, COMBO_END}; const uint16_t PROGMEM r_z_2_combo[] = {KC_RCBR, KC_LT, COMBO_END};
const uint16_t PROGMEM a_r_combo[] = {KC_A, KC_R, COMBO_END}; const uint16_t PROGMEM a_r_2_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM h_n_combo[] = {KC_H, KC_N, COMBO_END}; const uint16_t PROGMEM h_n_2_combo[] = {KC_HASH, KC_MINS, COMBO_END};
const uint16_t PROGMEM t_d_combo[] = {KC_T, KC_D, COMBO_END}; const uint16_t PROGMEM t_d_2_combo[] = {KC_RPRN, KC_DLR, COMBO_END};
const uint16_t PROGMEM i_o_combo[] = {KC_I, KC_O, COMBO_END}; const uint16_t PROGMEM i_o_2_combo[] = {KC_ASTR, KC_PLUS, COMBO_END};
// End paste from spreadsheet `def 1`

enum combos {
  // Begin paste from spreadsheet `def 2`
  C_k_m,   C_k_m_2,
  C_dot_quot,   C_dot_quot_2,
  C_y_excl,   C_y_excl_2,
  C_q_w,   C_q_w_2,
  C_e_dot,   C_e_dot_2,
  C_f_s,   C_f_s_2,
  C_l_n,   C_l_n_2,
  C_p_t,   C_p_t_2,
  C_u_e,   C_u_e_2,
  C_r_s_t,   C_r_s_t_2,
  C_n_e_i,   C_n_e_i_2,
  C_r_t,   C_r_t_2,
  C_e_o,   C_e_o_2,
  C_s_v,   C_s_v_2,
  C_w_f,   C_w_f_2,
  C_w_a,   C_w_a_2,
  C_q_r,   C_q_r_2,
  C_w_s,   C_w_s_2,
  C_f_t,   C_f_t_2,
  C_f_r,   C_f_r_2,
  C_p_s,   C_p_s_2,
  C_g_t,   C_g_t_2,
  C_j_l,   C_j_l_2,
  C_l_h,   C_l_h_2,
  C_u_n,   C_u_n_2,
  C_y_e,   C_y_e_2,
  C_excl_i,   C_excl_i_2,
  C_a_s,   C_a_s_2,
  C_n_i,   C_n_i_2,
  C_f_p,   C_f_p_2,
  C_r_s,   C_r_s_2,
  C_n_e,   C_n_e_2,
  C_e_m,   C_e_m_2,
  C_s_t_d,   C_s_t_d_2,
  C_x_c_v,   C_x_c_v_2,
  C_m_coma_dot,   C_m_coma_dot_2,
  C_w_f_p,   C_w_f_p_2,
  C_l_u_y,   C_l_u_y_2,
  C_s_t,   C_s_t_2,
  C_e_i,   C_e_i_2,
  C_i_coma,   C_i_coma_2,
  C_d_b,   C_d_b_2,
  C_n_m,   C_n_m_2,
  C_r_f_t,   C_r_f_t_2,
  C_n_u_i,   C_n_u_i_2,
  C_v_b,   C_v_b_2,
  C_p_g,   C_p_g_2,
  C_t_v,   C_t_v_2,
  C_h_k,   C_h_k_2,
  C_h_o,   C_h_o_2,
  C_x_c,   C_x_c_2,
  C_z_x,   C_z_x_2,
  C_m_coma,   C_m_coma_2,
  C_l_u,   C_l_u_2,
  C_w_r,   C_w_r_2,
  C_j_h,   C_j_h_2,
  C_g_d,   C_g_d_2,
  C_y_i,   C_y_i_2,
  C_x_v,   C_x_v_2,
  C_w_p,   C_w_p_2,
  C_m_coma_dot_quot,   C_m_coma_dot_quot_2,
  C_l_u_y_excl,   C_l_u_y_excl_2,
  C_m_dot,   C_m_dot_2,
  C_l_y,   C_l_y_2,
  C_coma_dot,   C_coma_dot_2,
  C_u_y,   C_u_y_2,
  C_c_v,   C_c_v_2,
  C_n_e_i_o,   C_n_e_i_o_2,
  C_n_o,   C_n_o_2,
  C_r_z,   C_r_z_2,
  C_a_r,   C_a_r_2,
  C_h_n,   C_h_n_2,
  C_t_d,   C_t_d_2,
  C_i_o,   C_i_o_2,
  // End paste from spreadsheet `def 2`
};

combo_t key_combos[COMBO_COUNT] = {
  // Begin paste from spreadsheet `def 3`
  [C_k_m] = COMBO(k_m_combo, KC_APP),   [C_k_m_2] = COMBO(k_m_2_combo, KC_APP),
  [C_dot_quot] = COMBO(dot_quot_combo, KC_BRID),   [C_dot_quot_2] = COMBO(dot_quot_2_combo, KC_BRID),
  [C_y_excl] = COMBO(y_excl_combo, KC_BRIU),   [C_y_excl_2] = COMBO(y_excl_2_combo, KC_BRIU),
  [C_q_w] = COMBO(q_w_combo, KC_BRK),   [C_q_w_2] = COMBO(q_w_2_combo, KC_BRK),
  [C_e_dot] = COMBO(e_dot_combo, KC_BSLASH),   [C_e_dot_2] = COMBO(e_dot_2_combo, KC_BSLASH),
  [C_f_s] = COMBO(f_s_combo, KC_BSPC),   [C_f_s_2] = COMBO(f_s_2_combo, KC_BSPC),
  [C_l_n] = COMBO(l_n_combo, KC_BSPC),   [C_l_n_2] = COMBO(l_n_2_combo, KC_BSPC),
  [C_p_t] = COMBO(p_t_combo, KC_DEL),   [C_p_t_2] = COMBO(p_t_2_combo, KC_DEL),
  [C_u_e] = COMBO(u_e_combo, KC_DEL),   [C_u_e_2] = COMBO(u_e_2_combo, KC_DEL),
  [C_r_s_t] = COMBO(r_s_t_combo, KC_DOWN),   [C_r_s_t_2] = COMBO(r_s_t_2_combo, KC_DOWN),
  [C_n_e_i] = COMBO(n_e_i_combo, KC_DOWN),   [C_n_e_i_2] = COMBO(n_e_i_2_combo, KC_DOWN),
  [C_r_t] = COMBO(r_t_combo, KC_END),   [C_r_t_2] = COMBO(r_t_2_combo, KC_END),
  [C_e_o] = COMBO(e_o_combo, KC_END),   [C_e_o_2] = COMBO(e_o_2_combo, KC_END),
  [C_s_v] = COMBO(s_v_combo, KC_ENT),   [C_s_v_2] = COMBO(s_v_2_combo, KC_ENT),
  [C_w_f] = COMBO(w_f_combo, KC_ESC),   [C_w_f_2] = COMBO(w_f_2_combo, KC_ESC),
  [C_w_a] = COMBO(w_a_combo, KC_F1),   [C_w_a_2] = COMBO(w_a_2_combo, KC_F1),
  [C_q_r] = COMBO(q_r_combo, KC_F10),   [C_q_r_2] = COMBO(q_r_2_combo, KC_F10),
  [C_w_s] = COMBO(w_s_combo, KC_F11),   [C_w_s_2] = COMBO(w_s_2_combo, KC_F11),
  [C_f_t] = COMBO(f_t_combo, KC_F12),   [C_f_t_2] = COMBO(f_t_2_combo, KC_F12),
  [C_f_r] = COMBO(f_r_combo, KC_F2),   [C_f_r_2] = COMBO(f_r_2_combo, KC_F2),
  [C_p_s] = COMBO(p_s_combo, KC_F3),   [C_p_s_2] = COMBO(p_s_2_combo, KC_F3),
  [C_g_t] = COMBO(g_t_combo, KC_F4),   [C_g_t_2] = COMBO(g_t_2_combo, KC_F4),
  [C_j_l] = COMBO(j_l_combo, KC_F5),   [C_j_l_2] = COMBO(j_l_2_combo, KC_F5),
  [C_l_h] = COMBO(l_h_combo, KC_F6),   [C_l_h_2] = COMBO(l_h_2_combo, KC_F6),
  [C_u_n] = COMBO(u_n_combo, KC_F7),   [C_u_n_2] = COMBO(u_n_2_combo, KC_F7),
  [C_y_e] = COMBO(y_e_combo, KC_F8),   [C_y_e_2] = COMBO(y_e_2_combo, KC_F8),
  [C_excl_i] = COMBO(excl_i_combo, KC_F9),   [C_excl_i_2] = COMBO(excl_i_2_combo, KC_F9),
  [C_a_s] = COMBO(a_s_combo, KC_HOME),   [C_a_s_2] = COMBO(a_s_2_combo, KC_HOME),
  [C_n_i] = COMBO(n_i_combo, KC_HOME),   [C_n_i_2] = COMBO(n_i_2_combo, KC_HOME),
  [C_f_p] = COMBO(f_p_combo, KC_INS),   [C_f_p_2] = COMBO(f_p_2_combo, KC_INS),
  [C_r_s] = COMBO(r_s_combo, KC_LEFT),   [C_r_s_2] = COMBO(r_s_2_combo, KC_LEFT),
  [C_n_e] = COMBO(n_e_combo, KC_LEFT),   [C_n_e_2] = COMBO(n_e_2_combo, KC_LEFT),
  [C_e_m] = COMBO(e_m_combo, KC_MINS),   [C_e_m_2] = COMBO(e_m_2_combo, KC_MINS),
  [C_s_t_d] = COMBO(s_t_d_combo, KC_MPLY),   [C_s_t_d_2] = COMBO(s_t_d_2_combo, KC_MPLY),
  [C_x_c_v] = COMBO(x_c_v_combo, KC_PGDN),   [C_x_c_v_2] = COMBO(x_c_v_2_combo, KC_PGDN),
  [C_m_coma_dot] = COMBO(m_coma_dot_combo, KC_PGDN),   [C_m_coma_dot_2] = COMBO(m_coma_dot_2_combo, KC_PGDN),
  [C_w_f_p] = COMBO(w_f_p_combo, KC_PGUP),   [C_w_f_p_2] = COMBO(w_f_p_2_combo, KC_PGUP),
  [C_l_u_y] = COMBO(l_u_y_combo, KC_PGUP),   [C_l_u_y_2] = COMBO(l_u_y_2_combo, KC_PGUP),
  [C_s_t] = COMBO(s_t_combo, KC_RGHT),   [C_s_t_2] = COMBO(s_t_2_combo, KC_RGHT),
  [C_e_i] = COMBO(e_i_combo, KC_RGHT),   [C_e_i_2] = COMBO(e_i_2_combo, KC_RGHT),
  [C_i_coma] = COMBO(i_coma_combo, KC_SLASH),   [C_i_coma_2] = COMBO(i_coma_2_combo, KC_SLASH),
  [C_d_b] = COMBO(d_b_combo, KC_TAB),   [C_d_b_2] = COMBO(d_b_2_combo, KC_TAB),
  [C_n_m] = COMBO(n_m_combo, KC_TAB),   [C_n_m_2] = COMBO(n_m_2_combo, KC_TAB),
  [C_r_f_t] = COMBO(r_f_t_combo, KC_UP),   [C_r_f_t_2] = COMBO(r_f_t_2_combo, KC_UP),
  [C_n_u_i] = COMBO(n_u_i_combo, KC_UP),   [C_n_u_i_2] = COMBO(n_u_i_2_combo, KC_UP),
  [C_v_b] = COMBO(v_b_combo, KC_VOLD),   [C_v_b_2] = COMBO(v_b_2_combo, KC_VOLD),
  [C_p_g] = COMBO(p_g_combo, KC_VOLU),   [C_p_g_2] = COMBO(p_g_2_combo, KC_VOLU),
  [C_t_v] = COMBO_ACTION(t_v_combo),   [C_t_v_2] = COMBO_ACTION(t_v_2_combo),
  [C_h_k] = COMBO_ACTION(h_k_combo),   [C_h_k_2] = COMBO_ACTION(h_k_2_combo),
  [C_h_o] = COMBO_ACTION(h_o_combo),   [C_h_o_2] = COMBO_ACTION(h_o_2_combo),
  [C_x_c] = COMBO_ACTION(x_c_combo),   [C_x_c_2] = COMBO_ACTION(x_c_2_combo),
  [C_z_x] = COMBO_ACTION(z_x_combo),   [C_z_x_2] = COMBO_ACTION(z_x_2_combo),
  [C_m_coma] = COMBO_ACTION(m_coma_combo),   [C_m_coma_2] = COMBO_ACTION(m_coma_2_combo),
  [C_l_u] = COMBO_ACTION(l_u_combo),   [C_l_u_2] = COMBO_ACTION(l_u_2_combo),
  [C_w_r] = COMBO_ACTION(w_r_combo),   [C_w_r_2] = COMBO_ACTION(w_r_2_combo),
  [C_j_h] = COMBO_ACTION(j_h_combo),   [C_j_h_2] = COMBO_ACTION(j_h_2_combo),
  [C_g_d] = COMBO_ACTION(g_d_combo),   [C_g_d_2] = COMBO_ACTION(g_d_2_combo),
  [C_y_i] = COMBO_ACTION(y_i_combo),   [C_y_i_2] = COMBO_ACTION(y_i_2_combo),
  [C_x_v] = COMBO_ACTION(x_v_combo),   [C_x_v_2] = COMBO_ACTION(x_v_2_combo),
  [C_w_p] = COMBO_ACTION(w_p_combo),   [C_w_p_2] = COMBO_ACTION(w_p_2_combo),
  [C_m_coma_dot_quot] = COMBO_ACTION(m_coma_dot_quot_combo),   [C_m_coma_dot_quot_2] = COMBO_ACTION(m_coma_dot_quot_2_combo),
  [C_l_u_y_excl] = COMBO_ACTION(l_u_y_excl_combo),   [C_l_u_y_excl_2] = COMBO_ACTION(l_u_y_excl_2_combo),
  [C_m_dot] = COMBO_ACTION(m_dot_combo),   [C_m_dot_2] = COMBO_ACTION(m_dot_2_combo),
  [C_l_y] = COMBO_ACTION(l_y_combo),   [C_l_y_2] = COMBO_ACTION(l_y_2_combo),
  [C_coma_dot] = COMBO_ACTION(coma_dot_combo),   [C_coma_dot_2] = COMBO_ACTION(coma_dot_2_combo),
  [C_u_y] = COMBO_ACTION(u_y_combo),   [C_u_y_2] = COMBO_ACTION(u_y_2_combo),
  [C_c_v] = COMBO_ACTION(c_v_combo),   [C_c_v_2] = COMBO_ACTION(c_v_2_combo),
  [C_n_e_i_o] = COMBO_ACTION(n_e_i_o_combo),   [C_n_e_i_o_2] = COMBO_ACTION(n_e_i_o_2_combo),
  [C_n_o] = COMBO_ACTION(n_o_combo),   [C_n_o_2] = COMBO_ACTION(n_o_2_combo),
  [C_r_z] = COMBO_ACTION(r_z_combo),   [C_r_z_2] = COMBO_ACTION(r_z_2_combo),
  [C_a_r] = COMBO_ACTION(a_r_combo),   [C_a_r_2] = COMBO_ACTION(a_r_2_combo),
  [C_h_n] = COMBO_ACTION(h_n_combo),   [C_h_n_2] = COMBO_ACTION(h_n_2_combo),
  [C_t_d] = COMBO_ACTION(t_d_combo),   [C_t_d_2] = COMBO_ACTION(t_d_2_combo),
  [C_i_o] = COMBO_ACTION(i_o_combo),   [C_i_o_2] = COMBO_ACTION(i_o_2_combo),
  // End paste from spreadsheet `def 3`
};

void process_combo_event(uint8_t combo_index, bool p) {
  switch(combo_index) {
    // Begin paste from spreadsheet `def 4`
    case C_t_v: if (p) {SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_TAB));} else {SEND_STRING(SS_UP(X_TAB)SS_UP(X_LSFT));} break;     case C_t_v_2: if (p) {SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_TAB));} else {SEND_STRING(SS_UP(X_TAB)SS_UP(X_LSFT));} break;
    case C_h_k: if (p) {SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_TAB));} else {SEND_STRING(SS_UP(X_TAB)SS_UP(X_LSFT));} break;     case C_h_k_2: if (p) {SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_TAB));} else {SEND_STRING(SS_UP(X_TAB)SS_UP(X_LSFT));} break;
    case C_h_o: if (p) {SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) SS_TAP(X_DEL));}  break;     case C_h_o_2: if (p) {SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) SS_TAP(X_DEL));}  break;
    case C_x_c: if (p) {SEND_STRING(SS_LCTL("c"));}  break;     case C_x_c_2: if (p) {SEND_STRING(SS_LCTL("c"));}  break;
    case C_z_x: if (p) {SEND_STRING(SS_LCTL("x"));}  break;     case C_z_x_2: if (p) {SEND_STRING(SS_LCTL("x"));}  break;
    case C_m_coma: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_DEL)SS_TAP(X_DEL));}  break;     case C_m_coma_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_DEL)SS_TAP(X_DEL));}  break;
    case C_l_u: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_BSPC)SS_TAP(X_BSPC));}  break;     case C_l_u_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_TAP(X_BSPC)SS_TAP(X_BSPC));}  break;
    case C_w_r: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;     case C_w_r_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;
    case C_j_h: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;     case C_j_h_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_BSPC));} else {SEND_STRING(SS_UP(X_BSPC)SS_UP(X_LCTL));} break;
    case C_g_d: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;     case C_g_d_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;
    case C_y_i: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;     case C_y_i_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_DEL));} else {SEND_STRING(SS_UP(X_DEL)SS_UP(X_LCTL));} break;
    case C_x_v: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL));}  break;     case C_x_v_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_END)SS_UP(X_LCTL));}  break;
    case C_w_p: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL));}  break;     case C_w_p_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL));}  break;
    case C_m_coma_dot_quot: if (p) {SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_LCTL("c")SS_TAP(X_END)SS_TAP(X_ENT)SS_LCTL("v"));}  break;     case C_m_coma_dot_quot_2: if (p) {SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_LCTL("c")SS_TAP(X_END)SS_TAP(X_ENT)SS_LCTL("v"));}  break;
    case C_l_u_y_excl: if (p) {SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_LCTL("c")SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_LEFT)SS_LCTL("v"));}  break;     case C_l_u_y_excl_2: if (p) {SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)SS_LCTL("c")SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_LEFT)SS_LCTL("v"));}  break;
    case C_m_dot: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_DEL));}  break;     case C_m_dot_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_DEL));}  break;
    case C_l_y: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_BSPC));}  break;     case C_l_y_2: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_BSPC));}  break;
    case C_coma_dot: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));}  break;     case C_coma_dot_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));}  break;
    case C_u_y: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_RGHT));}  break;     case C_u_y_2: if (p) {SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_ENT)SS_TAP(X_RGHT));}  break;
    case C_c_v: if (p) {SEND_STRING(SS_LCTL("v"));}  break;     case C_c_v_2: if (p) {SEND_STRING(SS_LCTL("v"));}  break;
    case C_n_e_i_o: if (p) {SEND_STRING(SS_LCTL("a"));}  break;     case C_n_e_i_o_2: if (p) {SEND_STRING(SS_LCTL("a"));}  break;
    case C_n_o: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT));}  break;     case C_n_o_2: if (p) {SEND_STRING(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT));}  break;
    case C_r_z: if (p) {SEND_STRING(SS_LCTL("z"));}  break;     case C_r_z_2: if (p) {SEND_STRING(SS_LCTL("z"));}  break;
    case C_a_r: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;     case C_a_r_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;
    case C_h_n: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;     case C_h_n_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LEFT));} else {SEND_STRING(SS_UP(X_LEFT)SS_UP(X_LCTL));} break;
    case C_t_d: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;     case C_t_d_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;
    case C_i_o: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;     case C_i_o_2: if (p) {SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_RGHT));} else {SEND_STRING(SS_UP(X_RGHT)SS_UP(X_LCTL));} break;
    // End paste from spreadsheet `def 4`
  }
}

