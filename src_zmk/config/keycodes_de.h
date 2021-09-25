/* Copyright 2016 Stephen Bösebeck
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

#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ ^ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ß │ ´ │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ Q │ W │ E │ R │ T │ Z │ U │ I │ O │ P │ Ü │ + │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ö │ Ä │ # │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ < │ Y │ X │ C │ V │ B │ N │ M │ , │ . │ - │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define DE_CIRC GRAVE // ^ (dead)
#define DE_SS   MINUS // ß
#define DE_ACUT EQUAL // ´ (dead)

// Row 2
#define DE_Q    Q            // Q
#define DE_W    W            // W
#define DE_E    E            // E
#define DE_R    R            // R
#define DE_T    T            // T
#define DE_Z    Y            // Z
#define DE_U    U            // U
#define DE_I    I            // I
#define DE_O    O            // O
#define DE_P    P            // P
#define DE_UDIA LEFT_BRACKET // Ü
#define DE_PLUS RIGHT_BRACE  // +

// Row 3
#define DE_A    A            // A
#define DE_S    S            // S
#define DE_D    D            // D
#define DE_F    F            // F
#define DE_G    G            // G
#define DE_H    H            // H
#define DE_J    J            // J
#define DE_K    K            // K
#define DE_L    L            // L
#define DE_ODIA SEMICOLON    // Ö
#define DE_ADIA SINGLE_QUOTE // Ä
#define DE_HASH NON_US_HASH  // #

// Row 4
#define DE_LABK NON_US_BACKSLASH // <
#define DE_Y    Z                // Y
#define DE_X    X                // X
#define DE_C    C                // C
#define DE_V    V                // V
#define DE_B    B                // B
#define DE_N    N                // N
#define DE_M    M                // M
#define DE_COMM COMMA            // ,
#define DE_DOT  PERIOD           // .
#define DE_MINS SLASH            // -

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ ° │ ! │ " │ § │ $ │ % │ & │ / │ ( │ ) │ = │ ? │ ` │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │ * │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │   │   │   │   │   │   │   │   │   │   │   │ ' │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ > │   │   │   │   │   │   │   │ ; │ : │ _ │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define DE_DEG  LS(DE_CIRC) // °
#define DE_EXLM LS(NUMBER_1)    // !
#define DE_DQUO LS(NUMBER_2)    // "
#define DE_SECT LS(NUMBER_3)    // §
#define DE_DLR  LS(NUMBER_4)    // $
#define DE_PERC LS(NUMBER_5)    // %
#define DE_AMPR LS(NUMBER_6)    // &
#define DE_SLSH LS(NUMBER_7)    // /
#define DE_LPRN LS(NUMBER_8)    // (
#define DE_RPRN LS(NUMBER_9)    // )
#define DE_EQL  LS(NUMBER_0)    // =
#define DE_QUES LS(DE_SS)   // ?
#define DE_GRV  LS(DE_ACUT) // ` (dead)
// Row 2
#define DE_ASTR LS(DE_PLUS) // *
// Row 3
#define DE_QUOT LS(DE_HASH) // '
// Row 4
#define DE_RABK LS(DE_LABK) // >
#define DE_SCLN LS(DE_COMM) // ;
#define DE_COLN LS(DE_DOT)  // :
#define DE_UNDS LS(DE_MINS) // _

/* Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ „ │ ¡ │ “ │ ¶ │ ¢ │ [ │ ] │ | │ { │ } │ ≠ │ ¿ │   │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ « │ ∑ │ € │ ® │ † │ Ω │ ¨ │ ⁄ │ Ø │ π │ • │ ± │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ Å │ ‚ │ ∂ │ ƒ │ © │ ª │ º │ ∆ │ @ │ Œ │ Æ │ ‘ │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ ≤ │ ¥ │ ≈ │ Ç │ √ │ ∫ │ ~ │ µ │ ∞ │ … │ – │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define DE_DLQU LA(DE_CIRC) // „
#define DE_IEXL LA(NUMBER_1)    // ¡
#define DE_LDQU LA(NUMBER_2)    // “
#define DE_PILC LA(NUMBER_3)    // ¶
#define DE_CENT LA(NUMBER_4)    // ¢
#define DE_LBRC LA(NUMBER_5)    // [
#define DE_RBRC LA(NUMBER_6)    // ]
#define DE_PIPE LA(NUMBER_7)    // |
#define DE_LCBR LA(NUMBER_8)    // {
#define DE_RCBR LA(NUMBER_9)    // }
#define DE_NEQL LA(NUMBER_0)    // ≠
#define DE_IQUE LA(DE_SS)   // ¿
// Row 2
#define DE_LDAQ LA(DE_Q)    // «
#define DE_NARS LA(DE_W)    // ∑
#define DE_EURO LA(DE_E)    // €
#define DE_REGD LA(DE_R)    // ®
#define DE_DAGG LA(DE_T)    // †
#define DE_OMEG LA(DE_Z)    // Ω
#define DE_DIAE LA(DE_U)    // ¨ (dead)
#define DE_FRSL LA(DE_I)    // ⁄
#define DE_OSTR LA(DE_O)    // Ø
#define DE_PI   LA(DE_P)    // π
#define DE_BULT LA(DE_UDIA) // •
#define DE_PLMN LA(DE_PLUS) // ±
// Row 3
#define DE_ARNG LA(DE_A)    // Å
#define DE_SLQU LA(DE_S)    // ‚
#define DE_PDIF LA(DE_D)    // ∂
#define DE_FHK  LA(DE_F)    // ƒ
#define DE_COPY LA(DE_G)    // ©
#define DE_FORD LA(DE_H)    // ª
#define DE_MORD LA(DE_J)    // º
#define DE_INCR LA(DE_K)    // ∆
#define DE_AT   LA(DE_L)    // @
#define DE_OE   LA(DE_ODIA) // Œ
#define DE_AE   LA(DE_ADIA) // Æ
#define DE_LSQU LA(DE_HASH) // ‘
// Row 4
#define DE_LTEQ LA(DE_LABK) // ≤
#define DE_YEN  LA(DE_Y)    // ¥
#define DE_AEQL LA(DE_X)    // ≈
#define DE_CCCE LA(DE_C)    // Ç
#define DE_SQRT LA(DE_V)    // √
#define DE_INTG LA(DE_B)    // ∫
#define DE_TILD LA(DE_N)    // ~ (dead)
#define DE_MICR LA(DE_M)    // µ
#define DE_INFN LA(DE_COMM) // ∞
#define DE_ELLP LA(DE_DOT)  // …
#define DE_NDSH LA(DE_MINS) // –

/* Shift+Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │   │ ¬ │ ” │   │ £ │ ﬁ │   │ \ │ ˜ │ · │ ¯ │ ˙ │ ˚ │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ » │   │ ‰ │ ¸ │ ˝ │ ˇ │ Á │ Û │   │ ∏ │   │  │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │   │ Í │ ™ │ Ï │ Ì │ Ó │ ı │   │ ﬂ │   │   │   │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ ≥ │ ‡ │ Ù │   │ ◊ │ ‹ │ › │ ˘ │ ˛ │ ÷ │ — │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define DE_NOT  LS(LA(NUMBER_1))    // ¬
#define DE_RDQU LS(LA(NUMBER_2))    // ”
#define DE_PND  LS(LA(NUMBER_4))    // £
#define DE_FI   LS(LA(NUMBER_5))    // ﬁ
#define DE_BSLS LS(LA(NUMBER_7))    // (backslash)
#define DE_STIL LS(LA(NUMBER_8))    // ˜
#define DE_MDDT LS(LA(NUMBER_9))    // ·
#define DE_MACR LS(LA(NUMBER_0))    // ¯
#define DE_DOTA LS(LA(DE_SS))   // ˙
#define DE_RNGA LS(LA(DE_ACUT)) // ˚
// Row 2
#define DE_RDAQ LS(LA(DE_Q))    // »
#define DE_PERM LS(LA(DE_E))    // ‰
#define DE_CEDL LS(LA(DE_R))    // ¸
#define DE_DACU LS(LA(DE_T))    // ˝
#define DE_CARN LS(LA(DE_Z))    // ˇ
#define DE_AACU LS(LA(DE_U))    // Á
#define DE_UCIR LS(LA(DE_I))    // Û
#define DE_NARP LS(LA(DE_P))    // ∏
#define DE_APPL LS(LA(DE_PLUS)) //  (Apple logo)
// Row 3
#define DE_IACU LS(LA(DE_S))    // Í
#define DE_TM   LS(LA(DE_D))    // ™
#define DE_IDIA LS(LA(DE_F))    // Ï
#define DE_IGRV LS(LA(DE_G))    // Ì
#define DE_OACU LS(LA(DE_H))    // Ó
#define DE_DLSI LS(LA(DE_J))    // ı
#define DE_FL   LS(LA(DE_L))    // ﬂ
// Row 4
#define DE_GTEQ LS(LA(DE_LABK)) // ≥
#define DE_DDAG LS(LA(DE_Y))    // ‡
#define DE_UGRV LS(LA(DE_X))    // Ù
#define DE_LOZN LS(LA(DE_V))    // ◊
#define DE_LSAQ LS(LA(DE_B))    // ‹
#define DE_RSAQ LS(LA(DE_N))    // ›
#define DE_BREV LS(LA(DE_M))    // ˘
#define DE_OGON LS(LA(DE_COMM)) // ˛
#define DE_DIV  LS(LA(DE_DOT))  // ÷
#define DE_MDSH LS(LA(DE_MINS)) // —