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
    TD_AEUE,
    TD_OESS,
    TD_CV,
    TD_HK,
    TD_COLN,
    TD_SLSH,
    TD_DLR_EUR,
    TD_AS_SL
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_AEUE] = ACTION_TAP_DANCE_DOUBLE(DE_ADIA, DE_UDIA),
    [TD_OESS] = ACTION_TAP_DANCE_DOUBLE(DE_ODIA, DE_SS),
    [TD_CV] = ACTION_TAP_DANCE_DOUBLE(DE_C, DE_V),
    [TD_HK] = ACTION_TAP_DANCE_DOUBLE(DE_H, DE_K),
    [TD_COLN] = ACTION_TAP_DANCE_DOUBLE(DE_COLN, DE_SCLN),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(DE_SLSH, DE_BSLS),
    [TD_DLR_EUR] = ACTION_TAP_DANCE_DOUBLE(DE_DLR, DE_EURO),
    [TD_AS_SL] = ACTION_TAP_DANCE_DOUBLE(DE_ASTR, DE_SLSH),
};

#define _C(key) LT(_CODE, key)
#define _T(key) LT(_TABLE, key)
#define _S(key) MT(MOD_LSFT, key)
#define _G(key) MT(MOD_LGUI, key)
#define _A(key) MT(MOD_LALT, key)
#define _L(key) MT(MOD_LCTL , key)

#define KC_AEUE TD(TD_AEUE)
#define KC_OESS TD(TD_OESS)
#define KC_CV TD(TD_CV)
#define KC_HK TD(TD_HK)
#define _G_COLN TD(TD_COLN)
#define _G_SLSH TD(TD_SLSH)
#define _G_DLR TD(TD_DLR_EUR)
#define _G_ASSL TD(TD_AS_SL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO,    DE_Z,_L(DE_L),_G(DE_U),_A(DE_A), _______,/*                                        */  _______,_A(DE_B),_G(DE_D),_L(DE_G),    DE_Y, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO,   KC_CV,_S(DE_R),_T(DE_I),_C(DE_E), _______,/*                                        */  _______,_C(DE_N),_T(DE_T),_S(DE_S),   KC_HK, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO, _______,    DE_X,    DE_Q, KC_AEUE, _______, _______, _______,/*    */  _______, _______, _______,    DE_F,  DE_DOT, DE_COMM, _______, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______,    DE_J,    DE_O, KC_OESS,/*    */     DE_P,    DE_M,    DE_W, _______, _______
    ),
    [_CODE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO,   DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, _______,/*                                        */  _______, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO, DE_HASH, _G_SLSH, DE_LCBR, DE_RCBR, _______,/*                                        */  _______, DE_LPRN, DE_RPRN, DE_MINS, _G_COLN, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO, _______,  _G_DLR, DE_PIPE, DE_TILD, _______, _______, _______,/*    */  _______, _______, _______, DE_PERC, DE_DQUO, DE_QUOT, _______, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______,  DE_GRV, DE_ASTR, DE_ACUT,/*    */  DE_PLUS, DE_QUES, DE_EXLM, _______, _______
    ),
    [_TABLE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO, KC_VOLU, KC_MPRV,   KC_UP, KC_MNXT, _______,/*                                        */  _______,    KC_7,    KC_8,    KC_9, _G_ASSL, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO, KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, _______,/*                                        */  _______,    KC_4,    KC_5,    KC_6, DE_MINS, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO, _______ , KC_TAB, KC_DEL , KC_BSPC, _______, _______, _______,/*    */  _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______,  KC_ESC,  KC_SPC,  KC_ENT,/*    */   DE_EQL,    KC_0, DE_PLUS, _______, _______
    ),
};

void *leader_open_func(uint16_t keycode) {
    switch (keycode) {
        // open apple music
        case DE_A:
            tap_code16(H(DE_A));
            break;
        // open google chrome
        case DE_C:
            tap_code16(H(DE_C));
            break;
        // open day one
        case DE_D:
            tap_code16(H(DE_Y));
            break;
        // open marta file manager
        case DE_F:
            tap_code16(H(DE_F));
            break;
        // open ia writer
        case DE_W:
            tap_code16(H(DE_W));
            break;
        // open slack
        case DE_L:
            tap_code16(H(DE_L));
            break;
        // open mail
        case DE_M:
            tap_code16(H(DE_M));
            break;
        // open 1password
        case DE_O:
            tap_code16(G(DE_HASH));
            break;
        // open things for reminders
        case DE_R:
            tap_code16(H(DE_R));
            break;
        // open firefox (for Surfing)
        case DE_S:
            tap_code16(H(DE_S));
            break;
        // open iterm
        case DE_T:
            tap_code16(H(DE_T));
            break;
        // open VS Code
        case DE_V:
            tap_code16(H(DE_V));
            break;
        // open Zoom:
        case DE_Z:
            tap_code16(H(DE_Z));
            break;
        default:
            break;
    }
    return NULL; // this function is always an endpoint
}

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

void *leader_media_func(uint16_t keycode) {
    switch (keycode) {
        // Focus Dock
        case DE_M:
            tap_code(KC_MUTE);
            break;
        case DE_P:
            tap_code16(KC_MPLY);
            break;
        default:
            break;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case DE_O:
            return leader_open_func; // function that opens common applications
        case DE_S:
            return leader_system_func;
        case DE_F:
            return leader_fkeys_func;
        case DE_M:
            return leader_media_func;
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
