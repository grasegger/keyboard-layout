#pragma once

#define _C(key) LT(_CODE, key)
#define _T(key) LT(_TABLE, key)
#define _S(key) MT(MOD_LSFT, key)
#define _G(key) MT(MOD_LGUI, key)
#define _A(key) MT(MOD_LALT, key)
#define _L(key) MT(MOD_LCTL , key)
#define H(key) S(C(A(G(key))))

#define KY_A _L(DE_A)
#define KY_B _L(DE_B)
#define KY_C DE_C
#define KY_D _G(DE_D)
#define KY_E DE_E
#define KY_F DE_F
#define KY_G _A(DE_G)
#define KY_H DE_H
#define KY_I _T(DE_I)
#define KY_J DE_J
#define KY_K DE_K
#define KY_L _A(DE_L)
#define KY_M DE_M
#define KY_N DE_N
#define KY_O DE_O
#define KY_P DE_P
#define KY_Q DE_Q
#define KY_R _S(DE_R)
#define KY_S _S(DE_S)
#define KY_T _T(DE_T)
#define KY_U _G(DE_U)
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
#define KY_COMM DE_COMM
#define KY_DOT DE_DOT
#define KY_SPC KC_SPC

#define KY_FIFX H(DE_S)
#define KY_CHRM H(DE_C)
#define KY_MAIL H(DE_M)
#define KY_TERM H(DE_T)
#define KY_MUSC H(DE_A)
#define KY_FILE H(DE_F)
#define KY_TODO H(DE_R)
#define KY_VSCO H(DE_V)
#define KY_IAWR H(DE_W)