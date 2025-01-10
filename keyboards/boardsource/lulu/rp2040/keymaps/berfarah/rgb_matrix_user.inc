RGB_MATRIX_EFFECT(rgb_move_layer)
RGB_MATRIX_EFFECT(rgb_window_layer)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/*
  ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  │ `   11 │ 1   10 │ 2   09 │ 3   08 │ 4   07 │ 5   06 │                          │ 6   41 │ 7   42 │ 8   43 │ 9   44 │ 0   45 │ BSP 46 │
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  │ TAB 12 │ Q   13 │ W   14 │ E   15 │ R   16 │ T   17 │                          │ Y   52 │ U   51 │ I   50 │ O   49 │ P   48 │ \   47 │
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  │ ESC 23 │ A   22 │ S   21 │ D   20 │ F   19 │ G   18 ├────────┐        ┌────────┤ H   53 │ J   54 │ K   55 │ L   56 │ ;   57 │ '   58 │
  ├────────┼────────┼────────┼────────┼────────┼────────┤ ROT 30 │        │ ROT 65 ├────────┼────────┼────────┼────────┼────────┼────────┤
  │ SFT 24 │ Z   25 │ X   26 │ C   27 │ V   28 │ B   29 ├────────┘        └────────┤ B   64 │ N   63 │ M   62 │ ,   61 │ .   60 │ /   59 │
  └────────┴────────┴───┬────┴───┬────┴───┬────┴───┬──┬─┴──────┐            ┌──────┴─┬──┬───┴────┬───┴────┬───┴────┬───┴────────┴────────┘
                        │ -   34 │ ALT 33 │ FN  32 │  │ GUI 31 │            │ SPC 66 │  │ FN  67 │ CTL 68 │ -   69 │
                        └────────┴────────┴────────┘  └────────┘            └────────┘  └────────┴────────┴────────┘
  ┌─────────────────────────────────────────────────────┐                          ┌─────────────────────────────────────────────────────┐
  │                                                     │                          │                                                     │
  │            04                05                06   │                          │   40                39                38            │
  │                                                     │                          │                                                     │
  │                                                     │                          │                                                     │
  │            03                                       └────────┐        ┌────────┘                                       37            │
  │                                                              │        │                                                              │
  │                              02                01          ┌─┘        └─┐          35                36                              │
  └─────────────────────┐                                      │            │                                      ┌─────────────────────┘
                        │                                      │            │                                      │
                        └──────────────────────────────────────┘            └──────────────────────────────────────┘
*/

static bool rgb_move_layer(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb;
        switch(i) {
        case 49 ... 51: // Media keys are green
            hsv_t green = {HSV_GREEN};
            rgb = rgb_matrix_hsv_to_rgb(green);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
        case 53 ... 56: // Movement keys are blue
            hsv_t blue = {HSV_BLUE};
            rgb = rgb_matrix_hsv_to_rgb(blue);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
        default:
            // Turn off
            rgb_matrix_set_color(i, 0, 0, 0);
            break;
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool rgb_window_layer(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        switch(i) {
        case 53 ... 56: // Window move keys are blue
        case 61:
        case 64:
            hsv_t hsv = {HSV_BLUE}; // Blue
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
        default:
            // Turn off
            rgb_matrix_set_color(i, 0, 0, 0);
            break;
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
