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

enum layers {
    _MINE = 0,
    _SYML, 
    _SYMR, 
    _NUML,
    _NUMR,
    _FL,
    _FR,
};


#include "keycodes.h"
#include "g/keymap_combo.h"


// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
          KY_Z,    KY_L,    KY_U,    KY_A,    KY_J,/*    */     KY_W,    KY_B,    KY_D,    KY_G,    KY_Y, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
          KY_C,    KY_R,    KY_I,    KY_E,    KY_O,/*    */     KY_M,    KY_N,    KY_T,    KY_S,    KY_H, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
          KY_V,    KY_X, KY_ADIA, KY_ODIA,    KY_Q,/*    */     KY_P,    KY_F,    KY_K, KY_UDIA,   KY_SS, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  KY_SHFT,  KY_DOT,/*    */  KY_COMM, KY_SPC
    ),

    [_SYML] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       DE_EURO, DE_UNDS, DE_LBRC, DE_RBRC,  DE_GRV,/*    */  _______, _______, _______, _______, _______,
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,/*    */  _______, _______, KC_LGUI, KC_LCTL, KC_LALT,
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       DE_HASH,  DE_DLR, DE_PIPE, DE_TILD, DE_ACUT,/*    */  _______, _______, _______, _______, _______,
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  _______ ,  DE_AT,/*    */  _______, KC_LSFT 
    ),

    [_SYMR] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       _______, _______, _______, _______, _______,/*    */  DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       KC_LALT, KC_LCTL, KC_LGUI, _______, _______,/*    */  DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       _______, _______, _______, _______, _______,/*    */  DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  KC_LSFT, _______,/*    */  _______, _______ 
    ),

    [_NUML] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       KC_PGUP,  KC_DEL,   KC_UP, KC_BSPC, KC_PGDN,/*    */  _______, _______, _______, _______, _______, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,/*    */  _______, KC_LGUI, _______, KC_LCTL, KC_LALT, 
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       _______,  KC_TAB,  KC_ESC,  KY_ENT, _______,/*    */  _______, _______, _______, _______, _______, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  KC_LSFT,DF(_MINE),/*    */DF(_NUML),KC_LSFT
    ),

    [_NUMR] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       _______, _______, _______, _______, _______,/*    */  DE_PLUS,    KC_7,    KC_8,    KC_9, DE_ASTR, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       KC_LALT, KC_LCTL, _______, KC_LGUI, _______,/*    */     KC_0,    KC_4,    KC_5,    KC_6,  DE_EQL, 
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       _______, _______, _______, _______, _______,/*    */  DE_MINS,    KC_1,    KC_2,    KC_3, DE_SLSH, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  KC_LSFT,DF(_MINE),/*    */DF(_NUMR),KC_LSFT
    ),

    [_FL] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       KC_WH_U, _______, KC_MS_U, _______, KC_WH_D,/*    */  _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,/*    */  _______, KC_LGUI, KC_LCTL, _______, KC_LALT, 
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       KC_BRMD, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRMU,/*    */  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  KC_LSFT,DF(_MINE),/*    */ DF(_FL), KC_LSFT
    ),

    [_FR] = LAYOUT(
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       _______, _______, _______, _______,   RESET,/*    */   KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_MNXT, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
       KC_LALT, _______, KC_LCTL, KC_LGUI, _______,/*    */   KC_F10,   KC_F4,   KC_F5,   KC_F6, KC_MPLY, 
    //--------|--------|--------|--------|--------|-\    /-|--------|--------|--------|--------|--------|
       _______, _______, _______, _______, _______,/*    */   KC_F11,   KC_F1,   KC_F2,   KC_F3, KC_MPRV, 
    //--------|--------|--------|--------|--------|-|    |-|--------|--------|--------|--------|--------|
                                  KC_LSFT,DF(_MINE),/*    */ DF(_FR), KC_LSFT
    ),
};

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}

#define hyperx(key) SEQ_ONE_KEY(KY_ ## key) { tap_code16(S(G(C(A(DE_ ## key))))); }
LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
   leading = false;

   hyperx(Z)
   hyperx(L)
   hyperx(U)
   hyperx(A)
   hyperx(J)
   hyperx(W)
   hyperx(B)
   hyperx(D)
   hyperx(G)
   hyperx(Y)
   hyperx(C)
   hyperx(R)
   hyperx(I)
   hyperx(E)
   hyperx(O)
   hyperx(M)
   hyperx(N)
   hyperx(T)
   hyperx(S)
   hyperx(H)
   hyperx(V)
   hyperx(X)
   hyperx(ADIA)
   hyperx(ODIA)
   hyperx(P)
   hyperx(F)
   hyperx(K)
   hyperx(UDIA)
   hyperx(SS)
   
   leader_end();
  }
}
