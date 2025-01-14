#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

#include "keymap_alias.h"

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

#define KC_RM_TOGG RM_TOGG
#define KC_RM_NEXT RM_NEXT
#define KC_RM_PREV RM_PREV

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
             RM_TOGG, _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
            // |----+----+----+----+----+----|              |----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  ,                _  ,RM_NEXT,RM_PREV, _  , _  , _  ,
            // |----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
                 _  , _  , _  , _  , _  , _  , _  ,     RGBK, _  , _  , _  , _  , _  , _  ,
            // `-------------------------------+--'    '----+-----------------------------'
                             _  , _  , _  , _  ,         _  , _  , _  , _
            //             `-------------------'       '-------------------'
            ),
};

enum rotary_mode {
    RGBM_HUE = 0,
    RGBM_SAT,
    RGBM_VAL,
    RGBM_SPEED,
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
        buffer[i+6] = 0x7f;
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
char spd_bar[24] = {};
void write_rgb_matrix_oled(void) {
    sprintf(hue_str, "%s %s %d", CURRENT_ROTARY_MODE == RGBM_HUE ? "*" : " ", "Hue", rgb_matrix_get_hue());
    oled_write_ln(hue_str, false);
    write_bar(sat_bar, CURRENT_ROTARY_MODE == RGBM_SAT, "Sat", rgb_matrix_get_sat(), 255);
    write_bar(val_bar, CURRENT_ROTARY_MODE == RGBM_VAL, "Val", rgb_matrix_get_val(), 255);
    write_bar(spd_bar, CURRENT_ROTARY_MODE == RGBM_SPEED, "Spd", rgb_matrix_get_speed(), 255);
}

char encoder_line[24] = {};
void write_oled_state(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

#ifdef RGB_MATRIX_SPLIT
    if (current_layer == _RGB) {
        write_rgb_matrix_oled();
    } else {
#endif
        oled_write_ln(read_custom_layer_state(), false);
        oled_write_ln("", false);
        sprintf(encoder_line, "%s %s", IS_LAYER_ON(_WIN) ? "\x97\x98" : "\x95\x96", current_layer == _NUMS ? "BRIGHTNESS" : "VOLUME");
        oled_write_ln(encoder_line, false);
        oled_write_ln(IS_LAYER_ON(_WIN) ? "\xB7\xB8" : "\xB5\xB6", false);
#ifdef RGB_MATRIX_SPLIT
    }
#endif
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        write_oled_state();
    }
    return false;
}
#endif // OLED Driver

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch(current_layer) {
        case _QWERTY:
        case _WIN:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _NUMS:
            if (clockwise) {
                tap_code(KC_BRIGHTNESS_UP);
            } else {
                tap_code(KC_BRIGHTNESS_DOWN);
            }
            break;
#ifdef RGB_MATRIX_SPLIT
        case _RGB:
            switch(CURRENT_ROTARY_MODE) {
                case RGBM_VAL:
                    if (clockwise) {
                        rgb_matrix_increase_val();
                    } else {
                        rgb_matrix_decrease_val();
                    }
                    break;
                case RGBM_HUE:
                    if (clockwise) {
                        rgb_matrix_increase_hue();
                    } else {
                        rgb_matrix_decrease_hue();
                    }
                    break;
                case RGBM_SAT:
                    if (clockwise) {
                        rgb_matrix_increase_sat();
                    } else {
                        rgb_matrix_decrease_sat();
                    }
                    break;
                case RGBM_SPEED:
                    if (clockwise) {
                        rgb_matrix_increase_speed();
                    } else {
                        rgb_matrix_decrease_speed();
                    }
                    break;
            }
            break;
#endif
    }

    return false;
}

int selected_mode_user = RGB_MATRIX_GRADIENT_UP_DOWN;
layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case _MOVE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_rgb_move_layer);
            break;
        case _WINDOW:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_rgb_window_layer);
            break;
        default:
            rgb_matrix_mode(selected_mode_user);
            break;
    }
    return state;
}

/* void set_keylog(uint16_t keycode, keyrecord_t *record); */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*     if (record->event.pressed) { */
/* #ifdef OLED_ENABLE */
/*         set_keylog(keycode, record); */
/* #endif */
/*         // set_timelog(); */
/*     } */

    bool is_windows_os = IS_LAYER_ON(_WIN);

    switch (keycode) {
        case KC_RGBK:
            if (record->event.pressed) {
                if (CURRENT_ROTARY_MODE == RGBM_SPEED) {
                    CURRENT_ROTARY_MODE = RGBM_HUE;
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LGUI_T(KC_F19):
            return 70;
        default:
            return TAPPING_TERM;
    }
}
