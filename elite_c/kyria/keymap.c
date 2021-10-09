/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef OSX
#include "keymap_german_osx.h"
#else
#include "keymap_german.h"
#endif

enum layers {
    _MINE = 0,
    _SYM,
    _NUM,
    _FUN
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    BSLS,
    SLSH,
    LCBR,
    RCBR,
    LPRN,
    RPRN,
    COLN,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
       _______,        DE_Z,        DE_L,    DE_U,            DE_A,     DE_J,                                                DE_W,        DE_B,        DE_D,       DE_G,         DE_Y, _______,
       _______, CTL_T(DE_C), ALT_T(DE_R), GUI_T(DE_I), SFT_T(DE_E),     DE_O,                                                DE_M, SFT_T(DE_N), GUI_T(DE_T), ALT_T(DE_S), CTL_T(DE_H), _______,
       _______,        DE_V,        DE_X,   OSL(_NUM),      KC_DOT,     DE_Q, _______, _______, _______,   _______,          DE_P,        DE_F,   OSL(_NUM),     KC_COMM,        DE_K, _______,
                                              _______,     _______,   KC_SPC, KC_BSPC, _______, _______, OSL(_SYM), OSM(MOD_LSFT),     _______,     _______
    ),

    [_SYM] = LAYOUT(
       _______,        DE_EURO,        DE_UNDS,        DE_LBRC,        DE_RBRC, DE_ACUT,                                        DE_EXLM,        DE_LABK,        DE_RABK,         DE_EQL,          DE_AT, _______,
       _______, TD(BSLS), TD(SLSH), TD(LCBR), TD(RCBR), DE_ASTR,                                        DE_QUES, TD(LPRN), TD(RPRN), ALT_T(DE_MINS), TD(COLN), _______,
       _______,        DE_HASH,         DE_DLR,        DE_PIPE,        DE_TILD,  DE_GRV, _______, _______, _______,   _______,  DE_PLUS,        DE_PERC,        DE_DQUO,        DE_QUOT,        DE_SCLN, _______,
                                                       _______,        _______, _______, _______, _______, _______, OSL(_FUN), TO(_MINE),       _______,        _______
    ),

    [_NUM] = LAYOUT(
       _______, KC_PGDN, KC_DEL, KC_UP, KC_BSPC, KC_PGUP,/*                                        */  KC_PEQL,    KC_P7,    KC_P8,    KC_P9, KC_PSLS, _______,
       _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,/*                                        */  KC_PPLS,    KC_P4,    KC_P5,    KC_P6,    KC_P0, _______,
       _______, KC_ESC, KC_TAB, TO(_NUM),  KC_ENT, TO(_MINE), _______, _______,/*    */  _______, _______, KC_PMNS,    KC_P1,    KC_P2,    KC_P3, KC_PAST, _______,
                                _______, _______,  DE_ADIA, DE_ODIA, _______,/*    */  _______, DE_UDIA, DE_SS, _______, _______
    ),

    [_FUN] = LAYOUT(
       _______, _______, _______, KC_BRMD, KC_BRMU, _______,/*                                        */  _______, KC_F7, KC_F8, KC_F9,KC_F12, _______,
       _______, CTL_T(KC_MPRV), ALT_T(KC_MNXT), GUI_T(KC_VOLD), SFT_T(KC_VOLU), _______,/*                                        */  _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
       _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______,/*    */  _______, _______,  _______, KC_F1, KC_F2, KC_F3, KC_F11, _______,
                         _______, _______,  _______, _______, _______,/*    */  _______, _______, _______, _______, _______
    ),

};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
   return true;
}


/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}


#define CREATE_MOD_TAP_DANCE(CODE, MOD) \
   static td_tap_t CODE ## tap_state = { \
    .is_press_action = true, \
    .state = TD_NONE \
}; \
\
void CODE ## _finished(qk_tap_dance_state_t *state, void *user_data) { \
    CODE ## tap_state.state = cur_dance(state); \
    switch (CODE ## tap_state.state) { \
        case TD_SINGLE_TAP: register_code16(DE_ ## CODE); break; \
        case TD_SINGLE_HOLD: register_code(KC_ ## MOD); break; \
        case TD_DOUBLE_TAP: register_code16(DE_ ## CODE); break; \
        case TD_DOUBLE_HOLD: register_code(KC_ ## MOD); break; \
        case TD_DOUBLE_SINGLE_TAP: tap_code16(DE_ ## CODE); register_code16(DE_ ## CODE); \
        default: break; \
    } \
} \
\
void CODE ## _reset(qk_tap_dance_state_t *state, void *user_data) { \
    switch (CODE ## tap_state.state) { \
        case TD_SINGLE_TAP: unregister_code16(DE_ ## CODE); break; \
        case TD_SINGLE_HOLD: unregister_code(KC_ ## MOD); break; \
        case TD_DOUBLE_TAP: unregister_code16(DE_ ## CODE); break; \
        case TD_DOUBLE_HOLD: unregister_code(KC_ ## MOD); \
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(DE_ ## CODE); \
        default: break; \
    } \
    CODE ## tap_state.state = TD_NONE; \
} 

CREATE_MOD_TAP_DANCE(BSLS, LCTL)
CREATE_MOD_TAP_DANCE(SLSH, LALT)
CREATE_MOD_TAP_DANCE(LCBR, LGUI)
CREATE_MOD_TAP_DANCE(RCBR, LSFT)
CREATE_MOD_TAP_DANCE(LPRN, LSFT)
CREATE_MOD_TAP_DANCE(RPRN, LGUI)
CREATE_MOD_TAP_DANCE(COLN, LCTL)

#define CREATE_MOD_TAP_DANCE_REGISTER(CODE) \
    [CODE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CODE ## _finished, CODE ##_reset),

qk_tap_dance_action_t tap_dance_actions[] = {
   CREATE_MOD_TAP_DANCE_REGISTER(BSLS)
   CREATE_MOD_TAP_DANCE_REGISTER(SLSH)
   CREATE_MOD_TAP_DANCE_REGISTER(LCBR)
   CREATE_MOD_TAP_DANCE_REGISTER(RCBR)
   CREATE_MOD_TAP_DANCE_REGISTER(LPRN)
   CREATE_MOD_TAP_DANCE_REGISTER(RPRN)
   CREATE_MOD_TAP_DANCE_REGISTER(COLN)
};