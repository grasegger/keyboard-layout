#pragma once

#ifdef OSX

#include "keymap_german_osx.h"

#define HRI(key) SFT_T(key) 
#define HRM(key) GUI_T(key)
#define HRR(key) ALT_T(key)
#define HRP(key) CTL_T(key)
#define HRE(key) key

#else

#include "keymap_german.h"

#define HRI(key) SFT_T(key) 
#define HRM(key) CTL_T(key)
#define HRR(key) ALT_T(key)
#define HRP(key) GUI_T(key)

#endif

#define LRI_L(key) LT(_SYM_RGHT, key)
#define LRM_L(key) LT(_NUM_RGHT, key)
#define LRR_L(key) LT(_EXT_RGHT, key)
#define LRP_L(key) LT(_FUN_RGHT, key)

#define LRP_R(key) LT(_FUN_LEFT, key)
#define LRR_R(key) LT(_EXT_LEFT, key)
#define LRM_R(key) LT(_NUM_LEFT, key)
#define LRI_R(key) LT(_SYM_LEFT, key)

#define KY_A DE_A
#define KY_B DE_B
#define KY_C HRP(DE_C)
#define KY_D DE_D
#define KY_E HRI(DE_E)
#define KY_F LRI_R(DE_F)
#define KY_G DE_G
#define KY_H HRP(DE_H)
#define KY_I HRM(DE_I)
#define KY_J DE_J
#define KY_K LRP_R(DE_K)
#define KY_L DE_L
#define KY_M HRE(DE_M)
#define KY_N HRI(DE_N)
#define KY_O HRE(DE_O)
#define KY_P DE_P
#define KY_Q LRM_L(DE_Q)
#define KY_R HRR(DE_R)
#define KY_S HRR(DE_S)
#define KY_T HRM(DE_T)
#define KY_U DE_U
#define KY_V LRP_L(KC_V)
#define KY_W DE_W
#define KY_X LRR_L(DE_X)
#define KY_Y DE_Y
#define KY_Z DE_Z
#define KY_BSPC KC_BSPC
#define KY_COMM LRM_R(DE_COMM)
#define KY_DOT LRR_R(DE_DOT)
#define KY_SPC LRI_L(KC_SPC)
#define KY_ENT KC_ENT
