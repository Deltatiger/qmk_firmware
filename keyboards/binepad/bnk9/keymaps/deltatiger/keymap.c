// Copyright 2023 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,
        KC_F13,    KC_F14,    KC_F15,
        KC_F16,    KC_F17,    KC_F18,
        TT(1),     KC_F19,    TT(2)
    ),
    [1] = LAYOUT(
        RM_TOGG,
        LSFT(KC_F13),    LSFT(KC_F14),    LSFT(KC_F15),
        PB_1,            PB_2,            PB_3,
        KC_TRNS,         LSFT(KC_F19),    KC_TRNS
    ),
    [2] = LAYOUT(
        RM_TOGG,
        LSFT(KC_F16),    LSFT(KC_F17),    LSFT(KC_F18),
        PB_4,	         PB_5,            PB_6,
        KC_TRNS,         LSFT(KC_F20),    KC_TRNS
    )
};

/**
 * Sets the color for each layer.
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    hsv_t hsv;

	switch (get_highest_layer(layer_state)) {
        case 0:
			hsv = (hsv_t) {130, 255, 255};
            break;
        case 1:
			hsv = (hsv_t) {205, 255, 255};
            break;
        case 2:
			hsv = (hsv_t) {28, 255, 255};
            break;
        default:
			hsv = (hsv_t) {85, 248, 255};
            break;
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    rgb_t rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return false;
}

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [1] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR) },
    [2] = { ENCODER_CCW_CW(RM_VALD, RM_VALU) }
};

#endif
