#pragma once

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 120
#define TAPPING_TERM_PER_KEY

#define MASTER_RIGHT

#undef OLED_FONT_H
#define OLED_FONT_H "mygldcfont.h"

#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#define RGB_MATRIX_HUE_STEP 1

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#define RGB_MATRIX_DEFAULT_HUE 205
#define RGB_MATRIX_DEFAULT_SAT 180
#define RGB_MATRIX_DEFAULT_VAL 80
#define RGB_MATRIX_DEFAULT_SPD 30


#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_TIMEOUT 60000

#ifdef ENCODER_ENABLE
#define ENCODER_RESOLUTION 2
#endif
