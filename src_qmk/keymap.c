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
#include "keymap_kyria.h"
#include "g/keymap_combo.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO,    KY_Z,    KY_L,    KY_U,    KY_A,    KY_J,/*                                        */     KY_W,    KY_B,    KY_D,    KY_G,    KY_Y, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO,    KY_C,    KY_R,    KY_I,    KY_E,    KY_O,/*                                        */     KY_M,    KY_N,    KY_T,    KY_S,    KY_H, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO,    KC_V,    KY_X, KY_ADIA, KY_ODIA,    KY_Q, _______, _______,/*    */  _______, _______,    KY_P,    KY_F,    KY_K, KY_UDIA,   KY_SS, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______, KY_COMM, KY_BSPC, _______,/*    */  _______,  KY_SPC,  KY_DOT, _______, _______
    ),

    [_TABLE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\                                        /-|--------|--------|--------|--------|--------|
KC_NO, KY_CHRM, KY_FIFX,   KC_UP, KY_TERM, KY_FILE,/*                                        */  _______,    KC_7,    KC_8,    KC_9, _______, KC_NO,
    //--------|--------|--------|--------|--------|-|                                        |-|--------|--------|--------|--------|--------|
KC_NO, KY_MAIL, KC_LEFT, KC_DOWN, KC_RGHT, KY_MUSC,/*                                        */     KC_0,    KC_4,    KC_5,    KC_6, _______, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|--------|--------|
KC_NO, _______, _______, KY_IAWR, KY_VSCO, KY_TODO, _______, _______,/*    */  _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, KC_NO,
    //--------|--------|--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                         _______, _______, _______, _______, _______,/*    */  _______, _______, _______, _______, _______
    ),
};

bool get_combo_must_tap(uint16_t index, combo_t *combo)  {
    return true;
}
