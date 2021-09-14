#pragma once

#ifdef OSX
#include "keymap_german_osx.h"
#else
#include "keymap_german.h"
#endif

#define KY_A GUI_T(DE_A)
#define KY_B GUI_T(DE_B)
#define KY_C LT(_FR, DE_C)
#define KY_D CTL_T(DE_D)
#define KY_E SFT_T(DE_E)
#define KY_F HYPR_T(DE_F)
#define KY_G ALT_T(DE_G)
#define KY_H LT(_FL,DE_H)
#define KY_I LT(_NUMR, DE_I)
#define KY_J DE_J
#define KY_K LT(_M, DE_K)
#define KY_L ALT_T(DE_L)
#define KY_M DE_M
#define KY_N SFT_T(DE_N)
#define KY_O DE_O
#define KY_P DE_P
#define KY_Q DE_Q
#define KY_R LT(_SYMR, DE_R)
#define KY_S LT(_SYML, DE_S)
#define KY_T LT(_NUML,DE_T)
#define KY_U CTL_T(DE_U)
#define KY_V KC_V
#define KY_W DE_W
#define KY_X DE_X
#define KY_Y DE_Y
#define KY_Z DE_Z
#define KY_ADIA LT(_M, DE_ADIA)
#define KY_ODIA HYPR_T(DE_ODIA)
#define KY_UDIA DE_UDIA
#define KY_SS DE_SS
#define KY_BSPC KC_BSPC
#define KY_COMM DE_COMM
#define KY_DOT DE_DOT
#define KY_SPC KC_SPC
#define KY_SHFT OSM(MOD_LSFT)
#define KY_ENT KC_ENT

#define KY_UNDO LGUI(DE_Z)
#define KY_REDO LGUI(LSFT(DE_Z))
#define KY_COPY LGUI(DE_C)
#define KY_PAST LGUI(DE_V)
#define KY_CUT  LGUI(DE_X)
#define KY_TNXT LCTL(KC_TAB)
#define KY_TPRV LCTL(LSFT(KC_TAB))
#define KY_TCLS LGUI(DE_W)