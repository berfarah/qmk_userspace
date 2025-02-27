#include QMK_KEYBOARD_H

#include "keymap_alias.h"

enum keyboard_layers {
    _QWERTY = 0, // default layer
    _NUMS,       // numbers + symbols
    _MOVE,       // VIM movement
    _WINDOW,     // Window movement
    _FKEYS,      // Function keys
};

enum custom_keycodes {
    KC_AFK = SAFE_RANGE,
};

#define KC_ KC_TRNS
#define KC__ KC_TRNS
#define _______ KC_TRNS

#define KC_RGB_HUI UG_HUEU
#define KC_RGB_VAI UG_SATU
#define KC_RGB_TOG UG_TOGG

// Tap: Escape, Hold: CTRL
#define KC_CLES CTL_T(KC_ESC)
// Toggle to NUMS layer
#define KC_NUMS MO(_NUMS)
// Toggle to FNKEYS layer
#define KC_FNKY MO(_FKEYS)
// Tap: ;, Hold: Toggle to VIM movement layer
#define KC_VSCN LT(_MOVE, KC_SCLN)
// Tap: /, Hold: Toggle to Window movement layer
#define KC_WSLH LT(_WINDOW, KC_SLSH)
// Command+`
#define KC_LGRV LGUI(KC_GRV)
#define KC_LGSP LGUI_T(KC_SPC)

#define KC_LLFT LGUI(KC_LEFT)
#define KC_LRHT LGUI(KC_RIGHT)
#define KC_VIMW LALT(KC_RIGHT)
#define KC_VIMB LALT(KC_LEFT)

#define KC_HYSP ALL_T(KC_F19)

#define KC_WINL LGUI(LALT(KC_LEFT))
#define KC_WINU LGUI(LALT(KC_UP))
#define KC_WIND LGUI(LALT(KC_DOWN))
#define KC_WINR LGUI(LALT(KC_RIGHT))
#define KC_CTAB LCTL(KC_TAB)
#define KC_LGUW LGUI(KC_W)

#define KC_RST RESET
#define KC_DBUG DEBUG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kc(
            //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
               TAB , Q  , W  , E  , R  , T  ,VOLU,      MNXT, Y  , U  , I  , O  , P  ,BSLS,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
               CLES, A  , S  , D  , F  , G  ,VOLD,      MPRV, H  , J  , K  , L  ,VSCN,QUOT,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
               LSFT, Z  , X  , C  , V  , B  ,MUTE,      MPLY, N  , M  ,COMM,DOT ,WSLH,RSFT,
            //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
               HYSP,LALT,FNKY,NUMS,LGUI, SPC,                BSPC, ENT,NUMS,FNKY,LALT,MEH
            //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
            ),

    [_NUMS] = LAYOUT_kc(
            //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
               LGRV,GRV , _  , _  , _  , _  ,RGB_HUI,   BRIU,  _  , _  , _ ,MINS, EQL,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ , 1  , 2  , 3  , 4  , 5  ,RGB_VAI,   BRID,  6  , 7 ,  8 ,  9 ,  0 ,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ ,  _ ,  _ ,  _ ,  _ ,  _ ,RGB_TOG,    AFK,  _ ,LPRN,RPRN,LBRC,RBRC,  _ ,
            //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
                 _ ,  _ ,  _ ,  _ ,  _ ,  _ ,                  _ ,  _ ,  _ ,  _ ,  _ ,  _
            //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
            ),

    [_MOVE] = LAYOUT_kc(
            //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
                 _ ,  _ ,VIMW, _  , _  ,CTAB, _  ,        _ , _  ,PGUP, _  , ENT,  _ ,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ , _  , _  ,PGDN, _  , _  , _  ,        _ ,LEFT,DOWN, UP ,RGHT,  _ ,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ ,  _ ,LGUW,  _ ,  _ ,VIMB, _  ,        _ ,  _ ,  _ ,  _ ,  _ ,  _ ,  _ ,
            //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
                 _ ,  _ ,  _ ,  _ ,  _ ,  _ ,                  _ ,  _ ,  _ ,  _ ,  _ ,  _
            //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
            ),

    [_WINDOW] = LAYOUT_kc(
            //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
                 _ ,  _ , _  , _  , _  , _  , _  ,        _ ,  _  , _  , _  , _ ,  _ ,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ , _  , _  , _  , _  , _  , _  ,        _ ,WINL,WIND,WINU,WINR,  _ ,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ ,  _ ,  _ ,  _ ,  _ ,  _ , _  ,        _ ,  _ ,  _ ,  _ ,  _ ,  _ ,  _ ,
            //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
                 _ ,  _ ,  _ ,  _ ,  _ ,  _ ,                  _ ,  _ ,  _ ,  _ ,  _ ,  _
            //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
            ),

    [_FKEYS] = LAYOUT_kc(
            //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
                 _ ,  _ , _  , _  , _  , _  , _  ,        _ ,  _  , _  , _  , _ ,  _ ,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ , F1 , F2 , F3 , F4 , F5 , _  ,        _ , F6 , F7 , F8 , F9 , F10,  _ ,
            //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                 _ , F11, F12, F13, F14, F15, _  ,        _ , F16, F17, F18, F19, F20,  _ ,
            //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
                 _ ,  _ ,  _ ,  _ ,  _ ,  _ ,                  _ ,  _ ,  _ ,  _ ,  _ ,  _
            //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
            )
};

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_AFK:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_PWR)));
            }
            return false; break;
    }

    return true;
};
