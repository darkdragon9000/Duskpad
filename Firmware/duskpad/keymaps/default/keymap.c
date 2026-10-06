// Copyright 2026 Aarav Batra (@darkdragon9000)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

static uint16_t mode_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        DP_MODE,   KC_P8,   KC_P9,   KC_PSLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PAST,
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
        KC_P0,   KC_PDOT, KC_PENT, KC_PPLS
    ),
    [1] = LAYOUT(
        DP_MODE, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [2] = LAYOUT(
        DP_MODE, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,  
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [3] = LAYOUT(
        DP_MODE, RGB_TOG, RGB_RMOD, RGB_MOD,
        RGB_HUD, RGB_HUI, RGB_VAD,  RGB_VAI,
        RGB_SAD, RGB_SAI, RGB_SPD,  RGB_SPI,
        KC_NO,   KC_NO,   EE_CLR,   QK_BOOT
    )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
    oled_write_P(PSTR("DuskPad"), false);
    oled_set_cursor(0, 1);

    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write_P(PSTR("Mode: Numpad"), false);
            break;
        case 1:
            oled_write_P(PSTR("Mode: Macro "), false);
            break;
        default:
            oled_write_P(PSTR("Mode: ?     "), false);
            break;
    }

    return false;
}
#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DP_MODE:
            if (record->event.pressed) {
                mode_timer = timer_read();
            } else {
                if (timer_elapsed(mode_timer) > TAPPING_TERM) {
                    uint8_t next = (get_highest_layer(default_layer_state) + 1) % 4;
                    set_single_persistent_default_layer(next);
                } else {
                    switch (get_highest_layer(default_layer_state)) {
                         case 0:
                        tap_code(KC_P7);
                        break;
                        case 1:
                         tap_code(KC_NO);
                        break;
                        case 2:
                        tap_code(KC_NO);
                        break;
                        case 3:
                        tap_code(DB_TOGG);
                        break;
    }
                }
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t mode = get_highest_layer(default_layer_state);
    rgb_matrix_set_color(16 + mode, RGB_PURPLE);
    return false;
}