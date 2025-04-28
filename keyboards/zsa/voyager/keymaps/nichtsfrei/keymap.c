#include <stdint.h>
#include "action.h"
#include "action_layer.h"
#include "action_util.h"
#include "bitwise.h"
#include "keycodes.h"
#include "modifiers.h"
#include "process_combo.h"
#include "quantum_keycodes.h"
#include "raw_hid.h"
#include QMK_KEYBOARD_H
#include "version.h"

#define ENTER LCTL_T(KC_ENTER)
#define SPACE LSFT_T(KC_SPACE)
#define TAB LALT_T(KC_TAB)
#define BSPC LGUI_T(KC_BSPC)

// Left-hand home row
#define HOME_A KC_A
#define HOME_S KC_S
#define HOME_D KC_D
#define HOME_F KC_F
#define HOME_F1 KC_F1
#define HOME_F2 KC_F2
#define HOME_F3 KC_F3
#define HOME_F4 KC_F4

// Right-hand home row
#define HOME_J KC_J
#define HOME_K KC_K
#define HOME_L KC_L
#define HOME_SCLN KC_SCLN
#define HOME_F7 KC_F7
#define HOME_F8 KC_F8
#define HOME_F9 KC_F9
#define HOME_F10 KC_F10

enum custom_keycodes { CKC_H = SAFE_RANGE, CKC_J, CKC_K, CKC_L, CKC_SEMICOLON, CKC_Q };
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // TODO: when familiar disable additional keys
  [0] = LAYOUT_voyager(
    KC_F11,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5 ,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,KC_F12,
    KC_RBRC,KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    KC_ESCAPE, HOME_A, HOME_S, HOME_D, HOME_F, KC_G ,   KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_QUOTE,
    KC_GRAVE,KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLS,
    SPACE, TAB                        ,   BSPC,ENTER
  ),

  [1] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_QUOTE, KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS, KC_1 , KC_2 , KC_3 , KC_4 , KC_5   ,    KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_TRNS,
    KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_EQUAL, KC_MINUS, KC_TRNS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, LSFT(KC_GRAVE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, LSFT(KC_QUOTE), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,
    KC_TRNS, LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5)   ,    LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , LSFT(KC_9) , LSFT(KC_0) , KC_TRNS,
    KC_TRNS, LSFT(KC_BSLS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_EQUAL), LSFT(KC_MINUS), KC_TRNS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),

  // TODO: media control? vim? tmux?
  [3] = LAYOUT_voyager(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_F11, KC_F12, KC_NO,
    KC_NO, HOME_F1 , HOME_F2 , HOME_F3 , HOME_F4 , KC_F5  ,    KC_F6 , HOME_F7 , HOME_F8 , HOME_F9 , HOME_F10 , KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT_voyager(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                                      QK_MOUSE_WHEEL_LEFT, QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_RIGHT, KC_NO, KC_NO,
    KC_NO, QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_4, QK_MOUSE_BUTTON_5,          QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_UP, QK_MOUSE_CURSOR_RIGHT, KC_NO, KC_NO,
    KC_NO, QK_MOUSE_ACCELERATION_0, QK_MOUSE_ACCELERATION_1, QK_MOUSE_ACCELERATION_2, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  // [2] = LAYOUT_voyager(
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_TRNS,
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS,
  //   KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS
  // ),
  [5] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, CKC_Q, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          CKC_H, CKC_J, CKC_K, CKC_L, CKC_SEMICOLON, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [6] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MEDIA_PLAY_PAUSE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_AUDIO_MUTE, KC_TRNS
  ),
  [7] = LAYOUT_voyager(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

};

// clang-format off
// #$%^&

const uint16_t PROGMEM combo_l_num[]  = {SPACE, TAB, COMBO_END};
const uint16_t PROGMEM combo_l_arrow[]  = {HOME_S, HOME_D, COMBO_END};
const uint16_t PROGMEM combo_l_brcks[]    = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM combo_r_sym[]    = {ENTER, BSPC, COMBO_END};
const uint16_t PROGMEM combo_lr_fun[]   = {SPACE, ENTER, COMBO_END};
const uint16_t PROGMEM combo_lr_mouse[] = {TAB, BSPC, COMBO_END};

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

const uint16_t PROGMEM combo_semicolon_p[] = {HOME_SCLN, KC_P, COMBO_END};
const uint16_t PROGMEM combo_l_o[]         = {HOME_L, KC_O, COMBO_END};
const uint16_t PROGMEM combo_k_i[]         = {HOME_K, KC_I, COMBO_END};
const uint16_t PROGMEM combo_y_u[]         = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_j_u[]         = {HOME_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_h_y[]         = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_a_q[]         = {HOME_A, KC_Q, COMBO_END};

const uint16_t PROGMEM combo_z_scolon[] = {KC_Z, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_a_scolon[] = {HOME_A, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_d_h[]      = {HOME_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_d_l[]      = {HOME_D, HOME_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_l_brcks, MO(5)),
    COMBO(combo_r_sym, MO(2)),
    COMBO(combo_lr_fun, MO(3)),
    COMBO(combo_lr_mouse, MO(4)),
    COMBO(combo_l_num, MO(1)),
    COMBO(combo_l_arrow, MO(6)),
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

void process_combo_event(uint16_t combo_index, bool pressed) {
    /*if (combo_index >= 0 && combo_index <= 3 && pressed) {*/
    /*    if (IS_LAYER_ON(combo_index + 1)) {*/
    /*        layer_clear();*/
    /*    } else {*/
    /*        // when triggering to*/
    /*        // with layer_move(2)*/
    /*        // it got confused and sent KC_NO.*/
    /*        // Therefore we clear and enable the specific layer.*/
    /*        layer_clear();*/
    /*        layer_on(combo_index + 1);*/
    /*    }*/
    /*}*/
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

#define NORMAL {0, 0, 69}
#define MOD {42, 42, 69}
#define NUM {210, 210, 69}
#define SYM {245, 245, 69}
#define FUN {255, 255, 69}
#define OUT {0, 0, 0}
// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {
      // left side
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL,
      // right side
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL
    },
    [1] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, NUM, OUT, OUT, OUT, OUT,
      OUT, NUM, NUM, NUM, NUM, NUM,
      OUT, NUM, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // right side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, NUM, NUM, NUM, OUT,
      NUM, NUM, NUM, NUM, NUM, OUT,
      OUT, OUT, OUT, NUM, NUM, OUT,
      OUT, OUT
    },

    [2] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, NUM, OUT, OUT, OUT, OUT,
      OUT, NUM, NUM, NUM, NUM, NUM,
      OUT, NUM, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // right side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, NUM, NUM, NUM, OUT,
      NUM, NUM, NUM, NUM, NUM, OUT,
      OUT, OUT, OUT, NUM, NUM, OUT,
      OUT, OUT
    },

    [3] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, FUN, FUN, FUN, FUN, FUN,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // right side
      OUT, OUT, OUT, OUT, OUT, OUT,
      FUN, FUN, FUN, FUN, FUN, OUT,
      FUN, FUN, FUN, FUN, FUN, OUT,
      FUN, FUN, OUT, OUT, OUT, OUT,
      OUT, OUT
    },
    [4] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, SYM, SYM, SYM, SYM, SYM,
      OUT, SYM, SYM, SYM, OUT, OUT,
      OUT, OUT,
      // right side
      OUT, OUT, OUT, OUT, OUT, OUT,
      SYM, SYM, SYM, SYM, OUT, OUT,
      SYM, SYM, SYM, SYM, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT
    },

    [5] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, MOD, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // OUT OUT
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      MOD, MOD, MOD, MOD, MOD, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT
    },

    [6] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // OUT OUT
      OUT, OUT, OUT, OUT, OUT, OUT,
      MOD, MOD, MOD, MOD, MOD, OUT,
      MOD, MOD, MOD, MOD, OUT, OUT,
      MOD, MOD, MOD, MOD, MOD, OUT,
      MOD, OUT
    },

    [7] = {
      // left side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // OUT OUT
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT
    },
};

// clang-format on
void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    set_layer_color(biton32(layer_state));
    return false;
}

uint8_t mod_state;

#define _SPECIAL_HANDLING(a, b, c)                   \
    do {                                             \
        if (record->event.pressed) {                 \
            if (mod_state & MOD_MASK_CTRL) {         \
                del_mods(MOD_MASK_CTRL);             \
                SEND_STRING(a SS_TAP(X_LEFT));       \
                set_mods(mod_state);                 \
            } else if (mod_state & MOD_MASK_SHIFT) { \
                del_mods(MOD_MASK_SHIFT);            \
                SEND_STRING(b);                      \
                set_mods(mod_state);                 \
            } else {                                 \
                SEND_STRING(c);                      \
            }                                        \
        }                                            \
    } while (0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case CKC_H:
            _SPECIAL_HANDLING("\"\"", "=>", "->");
            break;
        case CKC_SEMICOLON:
            _SPECIAL_HANDLING("''", "&&", "||");
            break;
        case CKC_J:
            _SPECIAL_HANDLING("()", ")", "(");
            break;
        case CKC_K:
            _SPECIAL_HANDLING("[]", "{", "[");
            break;
        case CKC_L:
            _SPECIAL_HANDLING("{}", "}", "]");
            break;
        case CKC_Q:
            _SPECIAL_HANDLING("``", "~", "`");
            break;
    }
    return true;
}
