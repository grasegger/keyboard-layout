#pragma once

#ifdef OSX
#include "keymap_german_osx.h"
#else
#include "keymap_german.h"
#endif

#define _SYM(key) LT(_SYM, key)
#define _NUM(key) LT(_NUM, key)
#define _GUI(key) MT(MOD_LGUI, key)
#define _ALT(key) MT(MOD_LALT, key)
#define _CTL(key) MT(MOD_LCTL , key)
#define _SFT(key) MT(MOD_LSFT, key)
#define H(key) S(C(A(G(key))))

#define KY_A DE_A
#define KY_B DE_B
#define KY_C _ALT(DE_C)
#define KY_D DE_D
#define KY_E _SFT(DE_E)
#define KY_F DE_F
#define KY_G DE_G
#define KY_H _ALT(DE_H)
#define KY_I _GUI(DE_I)
#define KY_J DE_J
#define KY_K DE_K
#define KY_L DE_L
#define KY_M DE_M
#define KY_N _SFT(DE_N)
#define KY_O DE_O
#define KY_P DE_P
#define KY_Q DE_Q
#define KY_R _CTL(DE_R)
#define KY_S _CTL(DE_S)
#define KY_T _GUI(DE_T)
#define KY_U DE_U
#define KY_V KC_V
#define KY_W DE_W
#define KY_X DE_X
#define KY_Y DE_Y
#define KY_Z DE_Z
#define KY_ADIA DE_ADIA
#define KY_ODIA DE_ODIA
#define KY_UDIA DE_UDIA
#define KY_SS DE_SS
#define KY_BSPC KC_BSPC
#define KY_COMM _SYM(DE_COMM)
#define KY_DOT DE_DOT
#define KY_SPC KC_SPC
#define KY_SHFT KC_LSFT
#define KY_ENT _NUM(KC_ENT)

#define KY_FIFX H(DE_S)
#define KY_MAIL H(DE_M)
#define KY_TERM H(DE_T)
#define KY_MUSC H(DE_A)
#define KY_TODO H(DE_R)
#define KY_FILE H(DE_F)
#define KY_VSCO H(DE_V)
#define KY_IAWR H(DE_W)
#define KY_DAYO H(DE_Y)
#define KY_CAL H(DE_K)

#define KY_NWDO H(KC_1)
#define KY_NOTE H(KC_2)

#define KY_PHPS H(DE_P)
#define KY_CHRM H(DE_C)
#define KY_SLCK H(DE_L)
