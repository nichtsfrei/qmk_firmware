/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 175

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"7qN4j/GEYzg"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 69
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1
