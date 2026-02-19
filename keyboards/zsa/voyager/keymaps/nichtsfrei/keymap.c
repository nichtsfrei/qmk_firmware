#include QMK_KEYBOARD_H

#define ENTER LCTL_T(KC_ENTER)
#define SPACE LSFT_T(KC_SPACE)
#define TAB LALT_T(KC_TAB)
#define BSPC LGUI_T(KC_BSPC)

// Left-hand home row
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_F1 LGUI_T(KC_F1)
#define HOME_F2 LALT_T(KC_F2)
#define HOME_F3 LCTL_T(KC_F3)
#define HOME_F4 LSFT_T(KC_F4)


#define HOME_1 LGUI_T(KC_1)
#define HOME_2 LALT_T(KC_2)
#define HOME_3 LCTL_T(KC_3)
#define HOME_4 LSFT_T(KC_4)

// Right-hand home row
#define HOME_J LSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define HOME_F7 LSFT_T(KC_F7)
#define HOME_F8 RCTL_T(KC_F8)
#define HOME_F9 RALT_T(KC_F9)
#define HOME_F10 RGUI_T(KC_F10)


#define HOME_7 LSFT_T(KC_7)
#define HOME_8 RCTL_T(KC_8)
#define HOME_9 RALT_T(KC_9)
#define HOME_0 RGUI_T(KC_0)

enum unicode_names {
    AE, AE_CAP, UE, UE_CAP, OE, OE_CAP, SS,
};

const uint32_t unicode_map[] = {
    [AE]     = 0x00E4, // ä
    [AE_CAP] = 0x00C4, // Ä
    [UE]     = 0x00FC, // ü
    [UE_CAP] = 0x00DC, // Ü
    [OE]     = 0x00F6, // ö
    [OE_CAP] = 0x00D6, // Ö
    [SS]     = 0x00DF, // ß
};


enum layouts {
    BASE = 0,
    NUMBERS,
    FUNCTION,
    MOUSE,
    L_UNDEFINED,
    // Special layer that should not be circled
    BRACKETS,
    NAVIGATION,
    UMLAUTE,
    LNUM,
    LNUMSHFT,
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    KC_NO,KC_NO, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_NO, KC_NO,
    KC_NO, KC_Q, HOME_S, HOME_D, HOME_F, KC_G ,   KC_H, HOME_J, HOME_K, HOME_L, KC_P, KC_NO,
    KC_NO,HOME_A, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMMA, KC_DOT, HOME_SCLN,KC_NO,
    KC_NO,  KC_Z, KC_NO, KC_NO, MO(FUNCTION), SPACE,   ENTER, MO(NUMBERS), KC_NO, KC_NO, KC_SLSH,KC_NO,
    KC_NO, KC_NO,   KC_NO, KC_NO
  ),

  [NUMBERS] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, HOME_2, HOME_3, HOME_4, KC_5   ,    KC_6 , HOME_7, HOME_8, HOME_9, KC_TRNS, KC_TRNS,
    KC_TRNS, HOME_1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, HOME_0, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_LLCK, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [FUNCTION] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, HOME_F2 , HOME_F3 , HOME_F4 , KC_F5  ,    KC_F6 , HOME_F7 , HOME_F8 , HOME_F9 , KC_F12, KC_TRNS,
    KC_TRNS, HOME_F1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, HOME_F10, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, QK_LLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [MOUSE] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                      QK_MOUSE_WHEEL_LEFT, QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_4, QK_MOUSE_BUTTON_5,          QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_UP, QK_MOUSE_CURSOR_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, QK_MOUSE_BUTTON_1, QK_MOUSE_ACCELERATION_1, QK_MOUSE_ACCELERATION_2, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, QK_MOUSE_ACCELERATION_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [L_UNDEFINED] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  // Here are special layer defined
  [BRACKETS] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_RPRN, KC_RBRC, KC_RCBR, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_AMPR, KC_LPRN, KC_LBRC, KC_LCBR, KC_HASH, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [UMLAUTE] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, UM(SS), UP(AE, AE_CAP), UP(UE, UE_CAP), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UP(OE, OE_CAP), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [NAVIGATION] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MEDIA_PLAY_PAUSE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_AUDIO_MUTE, QK_LLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  [LNUM] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS , KC_7, KC_8, KC_9, KC_0,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_6, KC_2, KC_3, KC_4, KC_5   ,    KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_LLCK, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),
  [LNUMSHFT] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS , LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, LSFT(KC_6), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5)   ,    KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, LSFT(KC_1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_LLCK, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
  ),



};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, FUNCTION, NUMBERS, MOUSE);
}

// clang-format off
const uint16_t PROGMEM combo_l_umlaute[]  = {HOME_A, HOME_S, COMBO_END};
const uint16_t PROGMEM combo_l_arrow[]  = {HOME_S, HOME_D, COMBO_END};
const uint16_t PROGMEM combo_l_brcks[]    = {HOME_D, HOME_F, COMBO_END};

const uint16_t PROGMEM combo_l_lnum[]    = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_l_lnumshft[]    = {HOME_L, HOME_K, COMBO_END};


const uint16_t PROGMEM combo_semicolon_p[] = {HOME_SCLN, KC_P, COMBO_END};
const uint16_t PROGMEM combo_l_o[]         = {HOME_L, KC_O, COMBO_END};
const uint16_t PROGMEM combo_k_i[]         = {HOME_K, KC_I, COMBO_END};
const uint16_t PROGMEM combo_y_u[]         = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_j_u[]         = {HOME_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_h_y[]         = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_a_q[]         = {HOME_A, KC_Q, COMBO_END};

const uint16_t PROGMEM combo_z_scolon[] = {KC_Z, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {HOME_F, HOME_J, COMBO_END};
const uint16_t PROGMEM combo_d_h[]      = {HOME_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_d_l[]      = {HOME_D, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {HOME_SCLN, HOME_A, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_l_umlaute, MO(UMLAUTE)),
    COMBO(combo_l_brcks, MO(BRACKETS)),
    COMBO(combo_l_arrow, MO(NAVIGATION)),
    COMBO(combo_l_lnum, MO(LNUM)),
    COMBO(combo_l_lnumshft, MO(LNUMSHFT)),

    COMBO(combo_z_scolon, KC_ESCAPE),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_d_h, KC_BSPC),
    COMBO(combo_d_l, KC_DELETE),
    COMBO(combo_enter, KC_ENTER),

    COMBO(combo_semicolon_p, KC_EQUAL),
    COMBO(combo_l_o, KC_MINUS),
    COMBO(combo_k_i, KC_QUOTE),
    COMBO(combo_j_u, KC_BACKSLASH),
    COMBO(combo_y_u, KC_LEFT_BRACKET),
    COMBO(combo_h_y, KC_RIGHT_BRACKET),
    COMBO(combo_a_q, KC_GRAVE),

};
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_LINUX);
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][3] = {
    [BASE]        = {0, 0, 0},  // off, default
    [NUMBERS]     = {40, 90, 150},    // warm amber: noticeable but gentle
    [FUNCTION]    = {220, 90, 160},   // muted violet: serious / meta
    [MOUSE]       = {120, 80, 140},   // subdued green: movement, not flashy
    [L_UNDEFINED] = {  0,   0,   0},  // off
    [BRACKETS]    = {160, 80, 150},   // teal-gray: structural, clear but calm
    [NAVIGATION]  = {10, 80, 130},    // deep red-orange: direction, low-key
    [UMLAUTE]     = {100,  70, 160},   // cool cyan: language / diacritics
    [LNUM]        = { 30, 110, 170},  // soft gold: left row numbers, slightly brighter
    [LNUMSHFT]    = {200,  70, 140},  // muted magenta: shifted symbols, related to function layer
};

typedef struct {
    uint8_t row;
    uint8_t col;
} led_rc_t;

const led_rc_t PROGMEM led_to_matrix[RGB_MATRIX_LED_COUNT] = {
    // LEFT HALF (0-25)
    {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6},      // k00-k05
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6},      // k06-k11
    {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6},      // k12-k17
    {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {4,4},      // k18-k23
    {5,0}, {5,1},                                   // k24-k25 (thumbs or lower row)

    // RIGHT HALF (26-51)
    {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5},      // k26-k31
    {7,0}, {7,1}, {7,2}, {7,3}, {7,4}, {7,5},      // k32-k37
    {8,0}, {8,1}, {8,2}, {8,3}, {8,4}, {8,5},      // k38-k43
    {10,2}, {9,1}, {9,2}, {9,3}, {9,4}, {9,5},     // k44-k49
    {11,5}, {11,6}                                  // k50-k51 (thumbs)
};



HSV get_color(int layer, uint8_t i) {

    uint8_t row = pgm_read_byte(&led_to_matrix[i].row);
    uint8_t col = pgm_read_byte(&led_to_matrix[i].col);

    uint16_t keycode = pgm_read_word(&keymaps[layer][row][col]);
    if (keycode == KC_TRNS) {
        keycode =  pgm_read_word(&keymaps[0][row][col]);
        layer = 0;
    }
    const uint8_t *lm = keycode == KC_NO ? ledmap[L_UNDEFINED] : ledmap[layer];

    HSV hsv = {
        .h = pgm_read_byte(&lm[0]),
        .s = pgm_read_byte(&lm[1]),
        .v = pgm_read_byte(&lm[2]),
    };
    return hsv;
}

// clang-format on
void set_layer_color(int layer) {
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
        const HSV hsv = get_color(layer, i);
        RGB   rgb = hsv_to_rgb(hsv);
        float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    set_layer_color(biton32(layer_state));
    return false;
}

