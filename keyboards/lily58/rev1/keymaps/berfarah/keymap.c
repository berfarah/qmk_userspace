#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

#include "keymap_alias.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum keyboard_layers {
    _QWERTY = 0, // default layer
    _WIN,        // windows layer
    _NUMS,       // numbers + symbols
    _MOVE,       // VIM movement
    _WINDOW,     // Window movement
    _RGB,        // RGB configuration
};

enum custom_keycodes {
    KC_AFK = SAFE_RANGE,
    KC_WINL,
    KC_WINU,
    KC_WIND,
    KC_WINR,
    KC_RGBK,
};


// Pretty empty buttons
#define KC_ KC_TRNS
#define KC__ KC_TRNS

// Toggle to Windows layer
#define KC_WIN TG(_WIN)
// Toggle to NUMS layer
#define KC_NUMS MO(_NUMS)
// Shift to RGB layer
#define KC_RGBM MO(_RGB)
// Tap: ;, Hold: Toggle to VIM movement layer
#define KC_VSCN LT(_MOVE, KC_SCLN)
// Tap: /, Hold: Toggle to Window movement layer
#define KC_WSLH LT(_WINDOW, KC_SLSH)
// Tap: Escape, Hold: CTRL
#define KC_CLES CTL_T(KC_ESC)
// Command+`
#define KC_LGRV LGUI(KC_GRV)

// Move window in thirds (Mac only)
#define KC_WTHL LCTL(LALT(KC_LEFT))
#define KC_WTHR LCTL(LALT(KC_RIGHT))

#define KC_LGF LGUI_T(KC_F19)

#define KC_VIMB LALT(KC_LEFT)
#define KC_LGUW LGUI(KC_W)
#define KC_CTAB LCTL(KC_TAB)
#define KC_VIMW LALT(KC_RIGHT)
#define KC_HYSP ALL_T(KC_F19)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [_QWERTY] = LAYOUT_kc(
            // ,-----------------------------.              ,-----------------------------.
                HYSP, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MEH ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                CLES, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,VSCN,QUOT,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                LSFT, Z  , X  , C  , V  , B  ,RGBM,     MUTE, N  , M  ,COMM,DOT ,WSLH,RSFT,
            // `-------------------------------+--'    '----+-----------------------------'
                            LALT,NUMS,LGF, SPC ,        BSPC,ENT ,NUMS,WIN
            //             `-------------------'       '-------------------'
            ),
    // Windows mode
    [_WIN] = LAYOUT_kc(
            // ,-----------------------------.              ,-----------------------------.
                ESC , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                LCTL, _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  , H  ,      _  , _  , _  , _  , _  , _  , _  ,
            // `-------------------------------+--'    '----+-----------------------------'
                            LGUI, _  ,LALT, _  ,         _  , _  , _  , _
            //             `-------------------'       '-------------------'
            ),
    // Number layer
    [_NUMS] = LAYOUT_kc(
            // ,-----------------------------.              ,-----------------------------.
                 _  , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 , F10, _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                LGRV,GRV , _  , _  , _  , _  ,                _  , _  , _  ,MINS,EQL , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , _  ,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,AFK ,      _  , _  ,LPRN,RPRN,LBRC,RBRC, _  ,
            // `-------------------------------+--'    '----+-----------------------------'
                             _  , _  , _  , _  ,         _  , _  , _  , _
            //             `-------------------'       '-------------------'
            ),
    // VIM Movement
    [_MOVE] = LAYOUT_kc(
            // ,-----------------------------.              ,-----------------------------.
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  ,VIMW, _  , _  ,CTAB,                _  ,MPRV,MPLY,MNXT, _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  ,PGDN, _  , _  ,               LEFT,DOWN, UP ,RGHT, _  , _  ,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                 _  , _  ,LGUW, _  , _  ,VIMB, _  ,      _  , _  , _  , _  , _  , _  , _  ,
            // `-------------------------------+--'    '----+-----------------------------'
                             _  , _  , _  , _  ,         _  , _  , _  , _
            //             `-------------------'       '-------------------'
            ),
    // Move windows
    [_WINDOW] = LAYOUT_kc(
            // ,-----------------------------.              ,-----------------------------.
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,               WINL,WINU,WIND,WINR, _  , _  ,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  , _  ,      _  ,WTHL, _  , _  ,WTHR, _  , _  ,
            // `-------------------------------+--'    '----+-----------------------------'
                             _  , _  , _  , _  ,         _  , _  , _  , _
            //             `-------------------'       '-------------------'
            ),
    // Configure RGB
    [_RGB] = LAYOUT_kc(
            // ,-----------------------------.              ,-----------------------------.
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  , _  ,     RGBK, _  , _  , _  , _  , _  , _  ,
            // `-------------------------------+--'    '----+-----------------------------'
                             _  , _  , _  , _  ,         _  , _  , _  , _
            //             `-------------------'       '-------------------'
            ),
};

enum rotary_mode {
    LED_HUE = 0,
    LED_SATURATION,
    LED_BRIGHTNESS,
    LED_MODE,
};
int CURRENT_ROTARY_MODE = 0;


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? rotation : OLED_ROTATION_180;
}


#define L_QWERTY 0
#define L_WIN 2
#define L_NUMS 4
#define L_MOVE 8
#define L_WINDOW 16

char layer_state_str[24];

const char *read_custom_layer_state(void) {
    switch (layer_state)
    {
        case L_QWERTY:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
            break;
        case L_WIN:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Windows");
            break;
        case L_NUMS:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numbers");
            break;
        case L_MOVE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: VIM");
            break;
        case L_WINDOW:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: VIMDow");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef");
    }

    return layer_state_str;
}


// When add source files to SRC in rules.mk, you can use functions.
const char *read_keylog(void);

void write_bar(char* buffer, bool selected, char *prefix, int value, int divisor) {
    char *seltext = selected ? "*" : " ";
    sprintf(buffer, "%s %s           ", seltext, prefix);

    // Replace the blanks with white squares based on % of value
    int amount = value*10 / divisor;
    amount = amount > 10 ? 10 : amount;
    for (int i = 0; i < amount; i++) {
        buffer[i+6] = 0x07;
    }

    oled_write_ln(buffer, false);
}

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

char hue_str[24] = {};
char sat_bar[24] = {};
char val_bar[24] = {};
char mode_str[24] = {};
void render_rgb_backlight(void) {
    sprintf(hue_str, "%s %s %d", CURRENT_ROTARY_MODE == LED_HUE ? "*" : " ", "Hue", rgblight_config.hue);
    oled_write_ln(hue_str, false);
    write_bar(sat_bar, CURRENT_ROTARY_MODE == LED_SATURATION, "Sat", rgblight_config.sat, 255);
    write_bar(val_bar, CURRENT_ROTARY_MODE == LED_BRIGHTNESS, "Val", rgblight_config.val, 255);
    sprintf(mode_str, "%s %s %d", CURRENT_ROTARY_MODE == LED_MODE ? "*" : " ", "Mod", rgblight_config.mode);
    oled_write_ln(mode_str, false);
}


void write_oled_state(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

#ifdef RGBLIGHT_ENABLE
    if (current_layer == _RGB) {
        render_rgb_backlight();
    } else {
#endif
        oled_write_ln(read_custom_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(current_layer == _QWERTY ? "VOLUME" : "BRIGHTNESS", false);
        oled_write_ln("", false);
#ifdef RGBLIGHT_ENABLE
    }
#endif
}

const char *read_logo(void);
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        write_oled_state();
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED Driver

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch(current_layer) {
        case _QWERTY:
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
            break;
        case _NUMS:
            if (clockwise) {
                tap_code(KC_BRIGHTNESS_DOWN);
            } else {
                tap_code(KC_BRIGHTNESS_UP);
            }
            break;
#ifdef RGBLIGHT_ENABLE
        case _RGB:
            switch(CURRENT_ROTARY_MODE) {
                case LED_BRIGHTNESS:
                    if (clockwise) {
                        rgblight_decrease_val();
                    } else {
                        rgblight_increase_val();
                    }
                    break;
                case LED_HUE:
                    if (clockwise) {
                        rgblight_decrease_hue();
                    } else {
                        rgblight_increase_hue();
                    }
                    break;
                case LED_SATURATION:
                    if (clockwise) {
                        rgblight_decrease_sat();
                    } else {
                        rgblight_increase_sat();
                    }
                    break;
                case LED_MODE:
                    if (clockwise) {
                        rgblight_step_reverse();
                    } else {
                        rgblight_step();
                    }
                    break;
            }
            break;
#endif
    }

    return false;
}

void set_keylog(uint16_t keycode, keyrecord_t *record);
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    bool is_windows_os = IS_LAYER_ON(_WIN);

    switch (keycode) {
        case KC_RGBK:
            if (record->event.pressed) {
                if (CURRENT_ROTARY_MODE == LED_MODE) {
                    CURRENT_ROTARY_MODE = LED_HUE;
                } else {
                    CURRENT_ROTARY_MODE++;
                }
                return false;
            }
            break;
        case KC_AFK:
            if (record->event.pressed) {
                is_windows_os ? tap_code16(LGUI(KC_L)) : tap_code16(LGUI(LCTL(KC_Q)));
                return false;
            }
            break;
        case KC_WINL:
            if (record->event.pressed) {
                is_windows_os ? tap_code16(LGUI(KC_LEFT)) : tap_code16(LGUI(LALT(KC_LEFT)));
                return false;
            }
            break;
        case KC_WINU:
            if (record->event.pressed) {
                is_windows_os ? tap_code16(LGUI(KC_UP)) : tap_code16(LGUI(LALT(KC_UP)));
                return false;
            }
            break;
        case KC_WIND:
            if (record->event.pressed) {
                is_windows_os ? tap_code16(LGUI(KC_DOWN)) : tap_code16(LGUI(LALT(KC_DOWN)));
                return false;
            }
            break;
        case KC_WINR:
            if (record->event.pressed) {
                is_windows_os ? tap_code16(LGUI(KC_RIGHT)) : tap_code16(LGUI(LALT(KC_RIGHT)));
            }
            break;
    }
    return true;
}


// Runs on startup – detect what operating system we're on, enable windows layer
// where needed.
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
        case OS_LINUX:
        case OS_UNSURE:
            layer_off(_WIN);
            break;
        case OS_WINDOWS:
            layer_on(_WIN);
            break;
    }

    return true;
}
