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

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
       _______, DE_Z, DE_L,      DE_U,          DE_A,   DE_J,                                                    DE_W,          DE_B,      DE_D,    DE_G, DE_Y, _______,
       _______, DE_C, DE_R,      DE_I,          DE_E,   DE_O,                                                    DE_M,          DE_N,      DE_T,    DE_S, DE_H, _______,
       _______, DE_V, DE_X, OSL(_NUM),        KC_DOT,   DE_Q,       _______, _______, _______, _______,          DE_P,          DE_F, OSL(_SYM), KC_COMM, DE_K, _______,
                              _______, OSM(MOD_LALT), KC_SPC, OSM(MOD_LGUI), _______, _______, KC_BSPC, OSM(MOD_LSFT), OSM(MOD_LCTL), _______
    ),

    [_SYM] = LAYOUT(
       _______, DE_EURO, DE_UNDS, DE_LBRC,       DE_RBRC, DE_ACUT,                                                 DE_EXLM,       DE_LABK,   DE_RABK,  DE_EQL, DE_PERC, _______,
       _______, DE_BSLS, DE_SLSH, DE_LCBR,       DE_RCBR, DE_ASTR,                                                 DE_QUES,       DE_LPRN,   DE_RPRN, DE_MINS, DE_COLN, _______,
       _______, DE_HASH,  DE_DLR, DE_PIPE,       DE_TILD,  DE_GRV,       _______, _______, _______, _______,       DE_PLUS,       DE_DQUO, OSL(_FUN), DE_QUOT, DE_SCLN, _______,
                                  _______, OSM(MOD_LALT),   DE_AT, OSM(MOD_LGUI), _______, _______, _______, OSM(MOD_LSFT), OSM(MOD_LCTL), _______
    ),

    [_NUM] = LAYOUT(
       _______, KC_PGDN , KC_DEL,    KC_UP,       KC_BSPC,   KC_PGUP,                                                 KC_PEQL,         KC_7,   KC_8, KC_9, KC_PSLS, _______,
       _______, KC_HOME, KC_LEFT,  KC_DOWN,      KC_RIGHT,    KC_END,                                                 KC_PPLS,         KC_4,   KC_5, KC_6,   KC_0, _______,
       _______,  KC_ESC , KC_TAB, TO(_NUM),        KC_ENT, TO(_MINE),       _______, _______, _______, _______,       KC_PMNS,         KC_1,   KC_2, KC_3, KC_PAST, _______,
                                   _______, OSM(MOD_LALT), KC_KP_DOT, OSM(MOD_LGUI), _______, _______, _______, OSM(MOD_LSFT), OSM(MOD_LCTL), _______
    ),

    [_FUN] = LAYOUT(
       _______, _______, _______, DE_UDIA,       DE_ADIA,     DE_SS,                                                _______,          KC_F7,   KC_F8, KC_F9,KC_F12, _______,
       _______, KC_MPRV, KC_MNXT, KC_VOLD,       KC_VOLU,   DE_ODIA,                                                _______,          KC_F4,   KC_F5, KC_F6, KC_F10, _______,
       _______, KC_BRMD, KC_BRMU, KC_MPLY,       KC_MUTE,   _______,       _______, _______, _______, _______,      _______,          KC_F1,   KC_F2, KC_F3, KC_F11, _______,
                                  _______, OSM(MOD_LALT), TO(_MINE), OSM(MOD_LGUI), _______, _______, _______, OSM(MOD_LSFT), OSM(MOD_LCTL), _______
    ),

};