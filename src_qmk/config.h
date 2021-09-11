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

#pragma once

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// comment the next line to build a firmware that works on linux and windows german qwertz layouts
#define OSX

#define COMBO_TERM 50
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_ONLY_FROM_LAYER 0

#define EE_HANDS

#define LEADER_TIMEOUT 250
#define LEADER_KEY_STRICT_KEY_PROCESSING
#define LEADER_NO_TIMEOUT

#define MK_COMBINED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_MOVE_DELTA 4