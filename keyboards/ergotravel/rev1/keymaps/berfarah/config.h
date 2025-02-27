/*
   Copyright 2017 Pierre Constantineau <jpconstantineau@gmail.com>

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

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_RIGHT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLIGHT_COUNT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_COUNT 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8


#undef TAPPING_TERM
#define TAPPING_TERM 150

#ifdef IGNORE_MOD_TAP_INTERRUPT
#undef IGNORE_MOD_TAP_INTERRUPT
#endif
