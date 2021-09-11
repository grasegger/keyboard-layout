#pragma once

#ifdef OSX
#include "keymap_german_osx.h"
#else
#include "keymap_german.h"
#endif

#define KY_A CTL_T(DE_A)
#define KY_B CTL_T(DE_B)
#define KY_C DE_C
#define KY_D GUI_T(DE_D)
#define KY_E LT(_SYMR, DE_E)
#define KY_F DE_F
#define KY_G ALT_T(DE_G)
#define KY_H DE_H
#define KY_I LT(_NUMR, DE_I)
#define KY_J DE_J
#define KY_K DE_K
#define KY_L ALT_T(DE_L)
#define KY_M DE_M
#define KY_N LT(_SYML,DE_N)
#define KY_O DE_O
#define KY_P DE_P
#define KY_Q DE_Q
#define KY_R LT(_FR, DE_R)
#define KY_S LT(_FL, DE_S)
#define KY_T LT(_NUML,DE_T)
#define KY_U GUI_T(DE_U)
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
