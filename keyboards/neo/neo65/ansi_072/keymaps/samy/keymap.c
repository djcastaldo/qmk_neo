/* 
Copyright 2023 NEO

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

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

// any custom keycodes you want to create can be listed here
// the first one should be set to NEW_SAFE_RANGE so it gets a number that doesn't conflict with other existing keycodes
enum custom_keycodes {
    CK_MYCODE = NEW_SAFE_RANGE,
    CK_ANOTHER,
    CK_THIRD,
    LLOCK
};

// you can name your layers here, whatever you want.  its easier to reference the names later than just using numbers.
enum layers {
    BASE_LAYR,
    FKEY_LAYR,
    THIRD_LAYR,
    LAYER_FOUR
};

// and use the same names from the enum above here.  the extra key on the top row is for the split backspace.  you don't have to use that, but it needs to be set here
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE_LAYR] = LAYOUT_hot(
		KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_DEL,   
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,  
		KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN, 
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,   KC_END, 
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT,MO(FKEY_LAYR),   KC_LEFT, KC_DOWN, KC_RIGHT
	),

	[FKEY_LAYR] = LAYOUT_hot(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, LLOCK,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
		_______,          RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,
		_______, MO(LAYER_FOUR), _______,                   _______,                            MO(THIRD_LAYR), _______,          _______, _______, _______     
	),

	[THIRD_LAYR] = LAYOUT_hot(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LLOCK,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, CK_MYCODE, CK_ANOTHER, _______, _______, _______, _______, _______,          _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______,          _______, _______, _______     
	),
	[LAYER_FOUR] = LAYOUT_hot(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LLOCK,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, CK_MYCODE, CK_ANOTHER, CK_THIRD, _______, _______, _______, _______,          _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______,          _______, _______, _______     
	)
};

// your own logic for custom keycodes goes here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // process layer lock if the LLOCK key was pressed
    if (!process_layer_lock(keycode, record, LLOCK)) {
       return false;
    }

    switch (keycode) {
        case CK_MYCODE:
            if (record->event.pressed) { // the key was pressed
                tap_code16(LGUI(KC_TAB)); // tap win + tab
            }
            return false; // stop further processing
        case CK_ANOTHER:
            if (record->event.pressed) { // the key was pressed
                SEND_STRING("CK_ANOTHER was pressed");
            }
            else { // the key was released
                SEND_STRING("CK_ANOTHER released");
            }
            return false;
        case CK_THIRD:
            if (record->event.pressed) {
                // open windows application folder
                send_string_with_delay(SS_LGUI(SS_TAP(X_R)) SS_DELAY(150) "shell:AppsFolder" SS_DELAY(50) SS_TAP(X_ENT),5);
            }
            return false;
    }

    return true; // this allows normal processing if the keycode doesn't match anything you defined above
}

// logic for rgb indicators goes here
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // get the current layer
    uint8_t layer = get_highest_layer(layer_state);
    // if on a layer higher than layer 0, then light up the keys that are assigned something other than KC_TRNS aka _______
    if (layer > BASE_LAYR) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    switch (layer) {
                        case FKEY_LAYR:
                            rgb_matrix_set_color(index, RGB_WHITE);
                            break;
                        case THIRD_LAYR:
                            rgb_matrix_set_color(index, RGB_GREEN);
                            break;
                        case LAYER_FOUR:
                            rgb_matrix_set_color(index, RGB_RED);
                            break;
                    }
                }
            }
        }
    }
    return false; // stop further rgb logic from functions outside this keymap.c
}
