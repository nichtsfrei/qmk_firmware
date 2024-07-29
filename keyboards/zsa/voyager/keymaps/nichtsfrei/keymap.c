#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "version.h"

// enum custom_keycodes {
//     ST_MACRO_0 = SAFE_RANGE,
// };

#define ENTER MT(MOD_LCTL, KC_ENTER)
#define SPACE MT(MOD_LSFT, KC_SPACE)
#define TAB MT(MOD_LGUI, KC_TAB)
#define BSPC MT(MOD_LALT, KC_BSPC)

#define MOD_A MT(MOD_LCTL, KC_A)
#define MOD_S MT(MOD_LALT, KC_S)
#define MOD_D MT(MOD_LGUI, KC_D)
#define MOD_F MT(MOD_MEH, KC_F)
#define MOD_G MT(MOD_HYPR, KC_G)
#define MOD_H MT(MOD_HYPR, KC_H)
#define MOD_J MT(MOD_MEH, KC_J)
#define MOD_K MT(MOD_LGUI, KC_K)
#define MOD_L MT(MOD_LALT, KC_L)
#define MOD_SEMICOLON MT(MOD_LCTL, KC_SEMICOLON)
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_EQUAL,  KC_1, KC_2, KC_3, KC_4, KC_5 ,   KC_6, KC_7, KC_8, KC_9, KC_0,KC_MINUS,
    KC_RBRC,KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G ,   KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE,
    KC_GRAVE,KC_Z, KC_X, KC_C, KC_V, KC_B   ,   KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLS,
    SPACE, TAB                        ,   BSPC,ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_TRNS, KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,                  KC_F6,KC_F7,KC_F8,KC_F9,KC_F10, KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, MOD_A, MOD_S, MOD_D, MOD_F, MOD_G,                    MOD_H, MOD_J, MOD_K, MOD_L, MOD_SEMICOLON, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

}; // clang-format on
const uint16_t PROGMEM combo_enter_f[]  = {ENTER, KC_F, COMBO_END};
const uint16_t PROGMEM combo_enter_mod_f[]  = {ENTER, MOD_F, COMBO_END};
const uint16_t PROGMEM combo_enter_s[]  = {ENTER, KC_S, COMBO_END};
const uint16_t PROGMEM combo_enter_mod_s[]  = {ENTER, MOD_S, COMBO_END};
const uint16_t PROGMEM combo_enter_a[]  = {ENTER, KC_A, COMBO_END};
const uint16_t PROGMEM combo_enter_mod_a[]  = {ENTER, MOD_A, COMBO_END};
const uint16_t PROGMEM combo_z_scolon[] = {KC_Z, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_z_mod_scolon[] = {KC_Z, MOD_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_a_scolon[] = {KC_A, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_a_mod_scolon[] = {MOD_A, MOD_SEMICOLON, COMBO_END};
const uint16_t PROGMEM combo_d_h[]      = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_d_mod_h[]      = {MOD_D, MOD_H, COMBO_END};
const uint16_t PROGMEM combo_d_l[]      = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_d_mod_l[]      = {MOD_D, MOD_L, COMBO_END};

const uint16_t PROGMEM combo_space_spc_enter[] = {SPACE, ENTER, COMBO_END};
const uint16_t PROGMEM combo_lbrc_minus[]      = {KC_MINUS, KC_LBRC, COMBO_END};
const uint16_t PROGMEM cmb_rbracket[]          = {KC_P, KC_LBRC, COMBO_END};
const uint16_t PROGMEM cmb_ws[]                = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM cmb_ws_mod[]                = {MOD_S, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_enter_f, TG(1)),
    COMBO(combo_enter_mod_f, TG(1)),
    COMBO(combo_enter_s, OSL(2)),
    COMBO(combo_enter_mod_s, OSL(2)),
    COMBO(combo_enter_a, TG(3)),
    COMBO(combo_enter_mod_a, TG(3)),
    COMBO(combo_z_scolon, KC_ESCAPE),
    COMBO(combo_z_mod_scolon, KC_ESCAPE),
    COMBO(combo_a_scolon, KC_ENTER),
    COMBO(combo_a_mod_scolon, KC_ENTER),
    COMBO(combo_d_h, KC_BSPC),
    COMBO(combo_d_mod_h, KC_BSPC),
    COMBO(combo_d_l, KC_DELETE),
    COMBO(combo_d_mod_l, KC_DELETE),
    COMBO(cmb_rbracket, KC_RBRC),
    COMBO(cmb_ws, KC_SPACE),
    COMBO(cmb_ws_mod, KC_SPACE),
    COMBO(combo_space_spc_enter, QK_CAPS_WORD_TOGGLE),
    COMBO(combo_lbrc_minus, KC_EQUAL),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return TAPPING_TERM;
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

#define NORMAL {0, 0, 69}
#define MOD {42,42,42}
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
      {0,0,0}, {195,246,120}, {195,246,120}, {195,246,120}, {195,246,120}, {195,246,120},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0},
      {195,246,120}, {195,246,120}, {195,246,120}, {195,246,120}, {195,246,120}, {195,246,120},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {195,246,120},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}
    },

    [2] = {
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
      {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {0,0,0},
      {0,153,153}, {0,153,153}, {0,153,153}, {0,153,153}, {0,0,0}, {0,0,0},
      {0,204,204}, {0,204,204}, {0,204,204}, {0,204,204}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}
    },

    [3] = {
      // left side
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, MOD, MOD, MOD, MOD, MOD,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL,
      // right side
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      MOD, MOD, MOD, MOD, MOD, NORMAL,
      NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
      NORMAL, NORMAL
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
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
