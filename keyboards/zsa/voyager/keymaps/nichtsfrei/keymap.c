#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "version.h"

// enum custom_keycodes {
//     ST_MACRO_0 = SAFE_RANGE,
// };

#define ENTER MT(MOD_LGUI, KC_ENTER)
#define SPACE MT(MOD_LSFT, KC_SPACE)
#define TAB MT(MOD_LCTL, KC_TAB)
#define BSPC MT(MOD_LALT, KC_BSPC)

// clang-format off
// num home row layer - z = \, i = ', o = [, p = ], . = -, / = =, q = `,
// symbol home row layer - shift + num, z = |, i = ", o = {, p = }, . = _, , = +, q = ~ = maybe not necessary as it is just shifted, probably better to create a specific german layer?
// F.. homw row layer with multimedia? - o = F11, p = F12, n = NXT_T, u = V_UP, i = V_DOWN, m = PRV_T, y = PAUSE,
// navigation home row layer, a = KC_END, s = PG_UP, d = PD_DWN, f = PG_HOME, h = KC_LEFT, j = KC_DOWN, k = KC_UP, l = KC_RIGHT
// mouse home row layer = a = left click, s = right click, d = middle click, y = scroll left, u = scroll down, k = scroll up, l = scroll right
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // TODO: when familiar disable additional keys
  [0] = LAYOUT_voyager(
    KC_EQUAL,  KC_1, KC_2, KC_3, KC_4, KC_5 ,   KC_6, KC_7, KC_8, KC_9, KC_0,KC_MINUS,
    KC_RBRC,KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G ,   KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE,
    KC_GRAVE,KC_Z, KC_X, KC_C, KC_V, KC_B   ,   KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLS,
    SPACE, TAB                        ,   BSPC,ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_QUOTE, KC_LBRC, KC_RBRC, KC_NO,
    KC_NO, KC_1 , KC_2 , KC_3 , KC_4 , KC_5  ,    KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_NO,
    KC_NO, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_EQUAL, KC_MINUS, KC_NO,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT_voyager(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_END, KC_PGUP, KC_PGDN, KC_HOME, KC_NO,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT_voyager(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_F11, KC_F12, KC_NO,
    KC_NO, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5  ,    KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_NO,
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
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

}; // clang-format on
//#$%^&

const uint16_t PROGMEM combo_l_num[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_l_num_b[] = {KC_7, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_l_sym[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_l_sym_b[] = {KC_PGUP, KC_PGDN, KC_HOME, COMBO_END};
const uint16_t PROGMEM combo_l_fun[] = {KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_l_fun_b[] = {KC_F7, KC_F8, KC_F9, KC_F10, COMBO_END};
const uint16_t PROGMEM combo_l_mse[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_l_mse_b[] = {QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_4, COMBO_END};


const uint16_t PROGMEM combo_z_scolon[] = {KC_Z, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_a_scolon[] = {KC_A, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_d_h[]      = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_d_l[]      = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_SEMICOLON, KC_SLASH, COMBO_END};

const uint16_t PROGMEM combo_space_spc_enter[] = {SPACE, ENTER, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_l_num, TG(1)),
    COMBO(combo_l_num_b, TG(1)),
    COMBO(combo_l_sym, TG(2)),
    COMBO(combo_l_sym_b, TG(2)),
    COMBO(combo_l_fun, TG(3)),
    COMBO(combo_l_fun_b, TG(3)),
    COMBO(combo_l_mse, TG(4)),
    COMBO(combo_l_mse_b, TG(4)),
    COMBO(combo_z_scolon, KC_ESCAPE),
    COMBO(combo_a_scolon, KC_ENTER),
    COMBO(combo_d_h, KC_BSPC),
    COMBO(combo_d_l, KC_DELETE),
    COMBO(combo_minus, KC_MINUS), // very useful to not have to switch layer
    COMBO(combo_space_spc_enter, QK_CAPS_WORD_TOGGLE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return TAPPING_TERM;
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

#define NORMAL {0, 0, 69}
#define MOD {42,42, 69}
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
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, SYM, SYM, SYM, SYM, SYM,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT,
      // right side
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      SYM, SYM, SYM, SYM, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
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
      OUT, MOD, MOD, MOD, MOD, MOD,
      OUT, MOD, MOD, MOD, OUT, OUT,
      OUT, OUT,
      // right side
      OUT, OUT, OUT, OUT, OUT, OUT,
      MOD, MOD, MOD, MOD, OUT, OUT,
      MOD, MOD, MOD, MOD, OUT, OUT,
      OUT, OUT, OUT, OUT, OUT, OUT,
      OUT, OUT
    },

    [5] = {
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
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
