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
#include "keymap_german_osx.h"
#include "features/leader.h"
#include "send_string.h"

enum layers {
    _MINE = 0,
    _CODE,
    _TABLE
};

enum my_keycodes {
    STRT_LD = SAFE_RANGE,
};

#include "g/keymap_combo.h"
enum {
    TD_DLR_EUR,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_DLR_EUR] = ACTION_TAP_DANCE_DOUBLE(DE_DLR, DE_EURO),
};

#define _C(key) LT(_CODE, key)
#define _T(key) LT(_TABLE, key)
#define _S(key) MT(MOD_LSFT, key)
#define _G(key) MT(MOD_LGUI, key)
#define _A(key) MT(MOD_LALT, key)
#define _L(key) MT(MOD_LCTL , key)

#define _G_DLR TD(TD_DLR_EUR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO,    DE_Z,_A(DE_L),_G(DE_U),_L(DE_A),    KC_J,/*                                        */     DE_W,_L(DE_B),_G(DE_D),_A(DE_G),    DE_Y, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO,    DE_C,_S(DE_R),_T(DE_I),_C(DE_E),    KC_O,/*                                        */     DE_M,_C(DE_N),_T(DE_T),_S(DE_S),    DE_H, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO,  KC_ESC,    DE_V,    DE_X,    DE_Q,    DE_K, _______, _______,/*    */  _______, _______,    DE_P,    DE_F,  DE_DOT, DE_COMM,  KC_ENT, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______, _______, KC_BSPC, _______,/*    */  _______,  KC_SPC, _______, _______, _______
    ),

    [_CODE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO,   DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_ACUT,/*                                        */  DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO, DE_HASH, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,/*                                        */  DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO, DE_BSLS,  _G_DLR, DE_PIPE, DE_TILD,  DE_GRV, _______, _______,/*    */  _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______, _______, KC_BSPC, _______,/*    */  _______,  KC_SPC, _______, _______, _______
    ),

    [_TABLE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO, KC_PGUP, _______,   KC_UP, _______, KC_PGDN,/*                                        */  DE_PLUS,    KC_7,    KC_8,    KC_9, DE_ASTR, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,/*                                        */   DE_EQL,    KC_4,    KC_5,    KC_6, DE_MINS, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO, _______, _______, _______, _______, _______, _______, _______,/*    */  _______, _______,    KC_0,    KC_1,    KC_2,    KC_3, DE_SLSH, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______, _______, KC_BSPC, _______,/*    */  _______,  KC_SPC, _______, _______, _______
    ),
};

void *leader_fkeys_func(uint16_t keycode) {
    // F Keys from top left to top right (F11 under F9, F12 under F10)
    switch (keycode) {
        case DE_Z:
            tap_code(KC_F1);
            break;
        case DE_L:
            tap_code(KC_F2);
            break;
        case DE_U:
            tap_code(KC_F3);
            break;
        case DE_A:
            tap_code(KC_F4);
            break;
        case DE_J:
            tap_code(KC_F5);
            break;
        case DE_W:
            tap_code(KC_F6);
            break;
        case DE_B:
            tap_code(KC_F7);
            break;
        case DE_D:
            tap_code(KC_F8);
            break;
        case DE_G:
            tap_code(KC_F9);
            break;
        case DE_Y:
            tap_code(KC_F10);
            break;
        case DE_S:
            tap_code(KC_F11);
            break;
        case DE_H:
            tap_code(KC_F12);
            break;
        default:
            break;
    }
    return NULL;
}

void *leader_system_func(uint16_t keycode) {
    switch (keycode) {
        // Focus Dock
        case DE_S:
            tap_code16(C(KC_F3));
            layer_move(_TABLE);
            break;
        // Toggle Do Not Disturb
        case DE_D:
            tap_code16(H(DE_D));
            break;
        // Switch off the light
        case DE_L:
            SPOT("osm");
            break;
        // Focus Menu Bar
        case DE_M:
            tap_code16(C(KC_F2));
            layer_move(_TABLE);
            break;
        // Focus on Tray
        case DE_T:
            tap_code16(C(KC_F8));
            layer_move(_TABLE);
            break;
        default:
            break;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case DE_S:
            return leader_system_func;
        case DE_F:
            return leader_fkeys_func;
        default:
            return NULL;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process leader key sequences
    if (!process_leader(keycode, record)) {
        return false;
    }
    switch(keycode) {
        case STRT_LD:
            if (record->event.pressed) {
                start_leading();
            }
            return false;
        default:
            return true;
    }
}
