#pragma once

#ifdef OSX
#include "keymap_german_osx.h"
#else
#include "keymap_german.h"
#endif

#define _NUM(key) LT(_TABLE, key)
#define _GUI(key) MT(MOD_LGUI, key)
#define _ALT(key) MT(MOD_LALT, key)
#define _CTL(key) MT(MOD_LCTL , key)
#define H(key) S(C(A(G(key))))

#define KY_A DE_A
#define KY_B DE_B
#define KY_C DE_C
#define KY_D DE_D
#define KY_E _CTL(DE_E)
#define KY_F DE_F
#define KY_G DE_G
#define KY_H DE_H
#define KY_I _NUM(DE_I)
#define KY_J DE_J
#define KY_K DE_K
#define KY_L DE_L
#define KY_M DE_M
#define KY_N DE_N
#define KY_O DE_O
#define KY_P DE_P
#define KY_Q DE_Q
#define KY_R _ALT(DE_R)
#define KY_S DE_S
#define KY_T DE_T
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
#define KY_COMM _GUI(DE_COMM)
#define KY_DOT _GUI(DE_DOT)
#define KY_SPC KC_SPC
#define KY_SHFT KC_LSFT

#define KY_FIFX H(DE_S)
#define KY_CHRM H(DE_C)
#define KY_MAIL H(DE_M)
#define KY_TERM H(DE_T)
#define KY_MUSC H(DE_A)
#define KY_FILE H(DE_F)
#define KY_TODO H(DE_R)
#define KY_VSCO H(DE_V)
#define KY_IAWR H(DE_W)
#define KY_ZOOM H(DE_Z)
#define KY_DAYO H(DE_Y)
#define KY_CAL H(DE_K)

#define _A_00 KY_Z
#define _A_01 KY_L
#define _A_02 KY_U
#define _A_03 KY_A
#define _A_04 KY_J
#define _A_05 KY_W
#define _A_06 KY_B
#define _A_07 KY_D
#define _A_08 KY_G
#define _A_09 KY_Y
#define _A_10 KY_C
#define _A_11 KY_R
#define _A_12 KY_I
#define _A_13 KY_E
#define _A_14 KY_O
#define _A_15 KY_M
#define _A_16 KY_N
#define _A_17 KY_T
#define _A_18 KY_S
#define _A_19 KY_H
#define _A_20 KY_V
#define _A_21 KY_X
#define _A_22 KY_ADIA
#define _A_23 KY_ODIA
#define _A_24 KY_Q
#define _A_25 KY_P
#define _A_26 KY_F
#define _A_27 KY_K
#define _A_28 KY_UDIA
#define _A_29 KY_SS
#define _A_30 KY_COMM
#define _A_31 KY_BSPC
#define _A_32 KY_SPC
#define _A_33 KY_DOT

#define CMB2(target, code_1, code_2) COMB(_ ## target, target, _A_ ## code_1, _A_ ## code_2)