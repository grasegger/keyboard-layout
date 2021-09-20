#pragma once

#ifdef OSX

#include "keymap_german_osx.h"

#define HRI(key) SFT_T(key) 
#define HRM(key) GUI_T(key)
#define HRR(key) ALT_T(key)
#define HRP(key) CTL_T(key)
#define HRE(key) HYPR_T(key)

#else

#include "keymap_german.h"

#define HRI(key) SFT_T(key) 
#define HRM(key) CTL_T(key)
#define HRR(key) ALT_T(key)
#define HRP(key) GUI_T(key)

#endif

enum tapdances {
    TD_COMM_DOT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COMM_DOT] = ACTION_TAP_DANCE_DOUBLE(DE_COMM, DE_DOT),
};


#define LEFT_INDX(key) LT(_SYMR, key)
#define LEFT_MIDD(key) LT(_NUMR, key)
#define LEFT_RING(key) LT(_EXTR, key)

#define RGHT_RING(key) LT(_EXTL, key)
#define RGHT_MIDD(key) LT(_NUML, key)
#define RGHT_INDX(key) LT(_SYML, key)

#define KY_A DE_A
#define KY_B DE_B
#define KY_C HRP(DE_C)
#define KY_D DE_D
#define KY_E HRI(DE_E)
#define KY_F RGHT_INDX(DE_F)
#define KY_G DE_G
#define KY_H HRP(DE_H)
#define KY_I HRM(DE_I)
#define KY_J DE_J
#define KY_K DE_K
#define KY_L DE_L
#define KY_M HRE(DE_M)
#define KY_N HRI(DE_N)
#define KY_O HRE(DE_O)
#define KY_P RGHT_MIDD(DE_P)
#define KY_Q LEFT_MIDD(DE_Q)
#define KY_R HRR(DE_R)
#define KY_S HRR(DE_S)
#define KY_T HRM(DE_T)
#define KY_U DE_U
#define KY_V KC_V
#define KY_W DE_W
#define KY_X LEFT_RING(DE_X)
#define KY_Y LEFT_INDX(DE_Y)
#define KY_Z RGHT_RING(DE_Z)
#define KY_BSPC KC_BSPC
#define KY_COMM TD(TD_COMM_DOT)
#define KY_SPC KC_SPC
#define KY_ENT KC_ENT

#define KY_TMIN DF(_MIN)
#define KY_NUML DF(_NUML)