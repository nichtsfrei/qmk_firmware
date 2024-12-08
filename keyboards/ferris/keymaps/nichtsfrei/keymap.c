#include QMK_KEYBOARD_H
// qmk flash -kb ferris/sweep -km nichtsfrei -e CONVERT_TO=promicro_rp2040 -bl uf2-split-left

void matrix_init_user(void) {
  debug_enable=false;
  debug_matrix=false;
  //debug_keyboard=true;
  //debug_mouse=true;
}


#define ENTER MT(MOD_LGUI, KC_ENTER)
#define SPACE MT(MOD_LSFT, KC_SPACE)
#define TAB MT(MOD_LCTL, KC_TAB)
#define BSPC MT(MOD_LALT, KC_BSPC)
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P,
     KC_A, KC_S, KC_D, KC_F, KC_G ,   KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON,
    KC_Z, KC_X, KC_C, KC_V, KC_B   ,   KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
    SPACE, TAB                        ,   BSPC,ENTER
  ),
  [1] = LAYOUT(
    KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_QUOTE, KC_LBRC, KC_RBRC,
    KC_1 , KC_2 , KC_3 , KC_4 , KC_5  ,    KC_6 , KC_7 , KC_8 , KC_9 , KC_0,
    KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_EQUAL, KC_MINUS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_END, KC_PGUP, KC_PGDN, KC_HOME, KC_NO,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_F11, KC_F12,
    KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5  ,    KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                                      QK_MOUSE_WHEEL_LEFT, QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_RIGHT, KC_NO,
    QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_4, QK_MOUSE_BUTTON_5,          QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_UP, QK_MOUSE_CURSOR_RIGHT, KC_NO,
    QK_MOUSE_ACCELERATION_0, QK_MOUSE_ACCELERATION_1, QK_MOUSE_ACCELERATION_2, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [5] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

};

// clang-format on
const uint16_t PROGMEM combo_l_fun[] = {TAB, ENTER, COMBO_END};
const uint16_t PROGMEM combo_l_mse[] = {TAB, BSPC, COMBO_END};
const uint16_t PROGMEM combo_l_num[] = {SPACE, ENTER, COMBO_END};
const uint16_t PROGMEM combo_l_sym[] = {SPACE, BSPC, COMBO_END};

const uint16_t PROGMEM combo_a_z[]            = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_s_x[]            = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo_d_c[]            = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_f_v[]            = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM combo_g_b[]            = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_h_n[]            = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_j_m[]            = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_k_comma[]        = {KC_K, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_l_period[]       = {KC_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_semicolon_slah[] = {KC_SEMICOLON, KC_SLASH, COMBO_END};

const uint16_t PROGMEM combo_semicolon_p[] = {KC_SEMICOLON, KC_P, COMBO_END};
const uint16_t PROGMEM combo_l_o[]         = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM combo_k_i[]         = {KC_K, KC_I, COMBO_END};
const uint16_t PROGMEM combo_y_u[]         = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_j_u[]         = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_h_y[]         = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_a_q[]         = {KC_A, KC_Q, COMBO_END};

const uint16_t PROGMEM combo_z_scolon[] = {KC_Z, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_a_scolon[] = {KC_A, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_d_h[]      = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_d_l[]      = {KC_D, KC_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_l_num, TG(1)),
    COMBO(combo_l_sym, TG(2)),
    COMBO(combo_l_fun, TG(3)),
    COMBO(combo_l_mse, TG(4)),
    COMBO(combo_z_scolon, KC_ESCAPE),
    COMBO(combo_a_scolon, KC_ENTER),
    COMBO(combo_d_h, KC_BSPC),
    COMBO(combo_d_l, KC_DELETE),

    COMBO(combo_semicolon_p, KC_EQUAL),
    COMBO(combo_l_o, KC_MINUS),
    COMBO(combo_k_i, KC_QUOTE),
    COMBO(combo_j_u, KC_BACKSLASH),
    COMBO(combo_y_u, KC_LEFT_BRACKET),
    COMBO(combo_h_y, KC_RIGHT_BRACKET),
    COMBO(combo_a_q, KC_GRAVE),

    COMBO(combo_a_z, KC_1),
    COMBO(combo_s_x, KC_2),
    COMBO(combo_d_c, KC_3),
    COMBO(combo_f_v, KC_4),
    COMBO(combo_g_b, KC_5),
    COMBO(combo_h_n, KC_6),
    COMBO(combo_j_m, KC_7),
    COMBO(combo_k_comma, KC_8),
    COMBO(combo_l_period, KC_9),
    COMBO(combo_semicolon_slah, KC_0),
};
