#include QMK_KEYBOARD_H
#include "raw_hid.h"

// qmk flash -kb ferris/sweep -km nichtsfrei -e CONVERT_TO=promicro_rp2040 -bl uf2-split-left
// qmk flash -kb ferris/sweep -km nichtsfrei -e CONVERT_TO=sparkfun_pm2040

void matrix_init_user(void) {
  debug_enable=false;
  debug_matrix=false;
  set_unicode_input_mode(UNICODE_MODE_LINUX);
  //debug_keyboard=true;
  //debug_mouse=true;
}

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

#define REPEAT QK_REPEAT_KEY
#define BACKBSE TO(0)

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


enum custom_keycodes {
    CKC_H = SAFE_RANGE,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_SEMICOLON,
    // don't collaps
};

enum layouts {
    BASE = 0,
    MOUSE,
    L_UNDEFINED,
    // Special layer that should not be circled
    BRACKETS,
    NAVIGATION,
    UMLAUTE,
    LNUM,
    LNUMSHFT,
    LFUN,
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P,
    HOME_A, HOME_S, HOME_D, HOME_F, KC_G ,   KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B   ,   KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
    BACKBSE, SPACE,   ENTER, REPEAT
  ),
  [MOUSE] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                      QK_MOUSE_WHEEL_LEFT, QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_RIGHT, KC_TRNS,
    QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_4, QK_MOUSE_BUTTON_5,          QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_UP, QK_MOUSE_CURSOR_RIGHT, KC_TRNS,
    QK_MOUSE_ACCELERATION_0, QK_MOUSE_ACCELERATION_1, QK_MOUSE_ACCELERATION_2, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),
  // Here are special layer defined
  [BRACKETS] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          CKC_H, CKC_J, CKC_K, CKC_L, CKC_SEMICOLON,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

  [UMLAUTE] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, UM(SS), UP(AE, AE_CAP), UP(UE, UE_CAP), UP(OE, OE_CAP),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

  [NAVIGATION] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),


  [LNUM] = LAYOUT(
    KC_6, KC_7, KC_8, KC_9, KC_0,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    HOME_1, HOME_2, HOME_3, HOME_4, KC_5,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

  [LFUN] = LAYOUT(
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    HOME_F1, HOME_F2, HOME_F3, HOME_F4, KC_F5,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

  [LNUMSHFT] = LAYOUT(
    LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS
  ),

};


// clang-format off
const uint16_t PROGMEM combo_l_umlaute[]  = {HOME_A, HOME_S, COMBO_END};
const uint16_t PROGMEM combo_l_arrow[]  = {HOME_S, HOME_D, COMBO_END};
const uint16_t PROGMEM combo_l_brcks[]    = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM combo_mouse[]    = {SPACE, ENTER, COMBO_END};

const uint16_t PROGMEM combo_l_lnum[]    = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_l_lnumshft[]    = {HOME_L, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_l_lfun[]    = {HOME_L, HOME_SCLN, COMBO_END};


const uint16_t PROGMEM combo_semicolon_p[] = {HOME_SCLN, KC_P, COMBO_END};
const uint16_t PROGMEM combo_l_o[]         = {HOME_L, KC_O, COMBO_END};
const uint16_t PROGMEM combo_k_i[]         = {HOME_K, KC_I, COMBO_END};
const uint16_t PROGMEM combo_y_u[]         = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_j_u[]         = {HOME_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_h_y[]         = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_a_q[]         = {HOME_A, KC_Q, COMBO_END};

const uint16_t PROGMEM combo_z_scolon[] = {KC_Z, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {HOME_F, HOME_J, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {HOME_SCLN, HOME_A, COMBO_END};

const uint16_t PROGMEM combo_bspc[]      = {HOME_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_bspc1[]      = {HOME_3, KC_H, COMBO_END};
const uint16_t PROGMEM combo_bspc2[]      = {LSFT(KC_3), KC_H, COMBO_END};

const uint16_t PROGMEM combo_del[]      = {HOME_D, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_del1[]      = {HOME_3, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_del2[]      = {LSFT(KC_3), HOME_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_l_umlaute, OSL(UMLAUTE)),
    COMBO(combo_l_brcks, OSL(BRACKETS)),
    COMBO(combo_l_arrow, OSL(NAVIGATION)),
    COMBO(combo_l_lnum, OSL(LNUM)),
    COMBO(combo_l_lnumshft, OSL(LNUMSHFT)),
    COMBO(combo_l_lfun, OSL(LFUN)),
    COMBO(combo_mouse, TG(MOUSE)),

    COMBO(combo_z_scolon, KC_ESCAPE),
    COMBO(combo_tab, KC_TAB),

    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_bspc1, KC_BSPC),
    COMBO(combo_bspc2, KC_BSPC),
    COMBO(combo_del, KC_DELETE),
    COMBO(combo_del1, KC_DELETE),
    COMBO(combo_del2, KC_DELETE),

    COMBO(combo_enter, KC_ENTER),

    COMBO(combo_semicolon_p, KC_EQUAL),
    COMBO(combo_l_o, KC_MINUS),
    COMBO(combo_k_i, KC_QUOTE),
    COMBO(combo_j_u, KC_BACKSLASH),
    COMBO(combo_y_u, KC_LEFT_BRACKET),
    COMBO(combo_h_y, KC_RIGHT_BRACKET),
    COMBO(combo_a_q, KC_GRAVE),
};


static layer_state_t send_state(layer_state_t state) {
    uint8_t data[32] = {0};
    data[0]          = 'L';
    data[1]          = 1;
    data[31]         = get_highest_layer(state);
    raw_hid_send(data, 32);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return send_state(state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return send_state(state);
}


void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (data[0] == 'L') {
        send_state(layer_state);
    }
}


static inline void with_cleared_mods(uint8_t mask, void (*fn)(void)) {
    uint8_t mods = get_mods();
    del_mods(mask);
    fn();
    set_mods(mods);
}

static void send_pair(uint16_t open, uint16_t close) {
    tap_code16(open);
    tap_code16(close);
    tap_code(KC_LEFT);
}

static bool normal_shift_ctrl_record(
    keyrecord_t *record,
    void (*normal_fn)(void),
    void (*shift_fn)(void),
    void (*ctrl_fn)(void)
) {
    if (!record->event.pressed) return false;

    uint8_t mods = get_mods();

    if (mods & MOD_MASK_CTRL) {
        with_cleared_mods(MOD_MASK_CTRL, ctrl_fn);
    } else if (mods & MOD_MASK_SHIFT) {
        with_cleared_mods(MOD_MASK_SHIFT, shift_fn);
    } else {
        normal_fn();
    }
    return false;


}

static void ckc_semicolon_normal(void) { send_pair(KC_QUOTE, KC_QUOTE); }
static void ckc_semicolon_shift(void)  { send_pair(KC_DQUO, KC_DQUO); }
static void ckc_semicolon_ctrl(void)   { send_pair(KC_GRAVE, KC_GRAVE); }

static void ckc_h_normal(void) { tap_code16(KC_EXCLAIM); tap_code16(KC_EQUAL); }
static void ckc_h_shift(void)  { tap_code16(KC_EQUAL); tap_code16(KC_GT); }
static void ckc_h_ctrl(void)   { tap_code16(KC_MINUS); tap_code16(KC_GT); }

static void ckc_j_normal(void) { send_pair(KC_LPRN, KC_RPRN); }
static void ckc_j_shift(void)  { tap_code16(KC_RPRN); }
static void ckc_j_ctrl(void)   { tap_code16(KC_LPRN); }

static void ckc_k_normal(void) { send_pair(KC_LBRC, KC_RBRC); }
static void ckc_k_shift(void)  { tap_code16(KC_RBRC); }
static void ckc_k_ctrl(void)   { tap_code16(KC_LBRC); }

static void ckc_l_normal(void) { send_pair(KC_LCBR, KC_RCBR); }
static void ckc_l_shift(void)  { tap_code16(KC_RCBR); }
static void ckc_l_ctrl(void)   { tap_code16(KC_LCBR); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_SEMICOLON:
            return normal_shift_ctrl_record(record, ckc_semicolon_normal, ckc_semicolon_shift, ckc_semicolon_ctrl);
        case CKC_H:
            return normal_shift_ctrl_record(record, ckc_h_normal, ckc_h_shift, ckc_h_ctrl);
        case CKC_J:
            return normal_shift_ctrl_record(record, ckc_j_normal, ckc_j_shift, ckc_j_ctrl);
        case CKC_K:
            return normal_shift_ctrl_record(record, ckc_k_normal, ckc_k_shift, ckc_k_ctrl);
        case CKC_L:
            return normal_shift_ctrl_record(record, ckc_l_normal, ckc_l_shift, ckc_l_ctrl);
    }
    return true;

}
