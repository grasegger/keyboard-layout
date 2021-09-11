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
#define _F(key) LT(_F, key)
#define H(key) S(C(A(G(key))))

#define KY_A _CTL(DE_A)
#define KY_B _CTL(DE_B)
#define KY_C DE_C
#define KY_D _GUI(DE_D)
#define KY_E _SYM(DE_E)
#define KY_F DE_F
#define KY_G _ALT(DE_G)
#define KY_H DE_H
#define KY_I _NUM(DE_I)
#define KY_J DE_J
#define KY_K DE_K
#define KY_L _ALT(DE_L)
#define KY_M DE_M
#define KY_N _SYM(DE_N)
#define KY_O DE_O
#define KY_P DE_P
#define KY_Q DE_Q
#define KY_R _F(DE_R)
#define KY_S _F(DE_S)
#define KY_T _NUM(DE_T)
#define KY_U _GUI(DE_U)
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
#define KY_SHFT OSM(MOD_LSFT)
#define KY_ENT KC_ENT

#define FIREFOX H(DE_S)
#define MAIL H(DE_M)
#define TERMINAL H(DE_T)
#define MUSIC H(DE_A)
#define VSCODE H(DE_V)
#define CALENDAR H(DE_K)
#define PHPSTORM H(DE_P)
#define CHROME H(DE_C)
#define SLACK H(DE_L)
#define TODO H(DE_R)
#define FILES H(DE_F)
#define IAWRITER H(DE_W)


#define NEWTODO H(KC_1)
#define NEWNOTE H(KC_2)

