/*
   This is the c configuration file for the keymap

   Copyright 2012 Jun Wako <wakojun@gmail.com>
   Copyright 2015 Jack Humbert

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */

#pragma once

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 100
// Consider per-key tapping term with shorter timeout for LGUI if it's too annoying

#define MASTER_RIGHT

#undef OLED_FONT_H
#define OLED_FONT_H "mygldcfont.h"

#undef  RGBLIGHT_LED_COUNT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LED_COUNT 8
#define RGBLED_SPLIT { 4, 4 }
#define RGBLIGHT_HUE_STEP 1
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_TIMEOUT 60000

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A {}
#define ENCODERS_PAD_B {}
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 4
#endif
