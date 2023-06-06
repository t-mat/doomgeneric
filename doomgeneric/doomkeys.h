//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//       Key definitions
//

#ifndef __DOOMKEYS__
#define __DOOMKEYS__

enum {
    //
    // DOOM keyboard definition.
    // This is the stuff configured by Setup.Exe.
    // Most key data are simple ascii (uppercased).
    //
    KEY_RIGHTARROW   = 0xae,
    KEY_LEFTARROW    = 0xac,
    KEY_UPARROW      = 0xad,
    KEY_DOWNARROW    = 0xaf,
    KEY_STRAFE_L     = 0xa0,
    KEY_STRAFE_R     = 0xa1,
    KEY_USE          = 0xa2,
    KEY_FIRE         = 0xa3,
    KEY_ESCAPE       = 27,
    KEY_ENTER        = 13,
    KEY_TAB          = 9,
    KEY_F1           = (0x80+0x3b),
    KEY_F2           = (0x80+0x3c),
    KEY_F3           = (0x80+0x3d),
    KEY_F4           = (0x80+0x3e),
    KEY_F5           = (0x80+0x3f),
    KEY_F6           = (0x80+0x40),
    KEY_F7           = (0x80+0x41),
    KEY_F8           = (0x80+0x42),
    KEY_F9           = (0x80+0x43),
    KEY_F10          = (0x80+0x44),
    KEY_F11          = (0x80+0x57),
    KEY_F12          = (0x80+0x58),
    KEY_BACKSPACE    = 0x7f,
    KEY_PAUSE        = 0xff,
    KEY_EQUALS       = 0x3d,
    KEY_MINUS        = 0x2d,
    KEY_RSHIFT       = (0x80+0x36),
    KEY_RCTRL        = (0x80+0x1d),
    KEY_RALT         = (0x80+0x38),
    KEY_LALT         = KEY_RALT,

    // new keys:
    KEY_CAPSLOCK    = (0x80+0x3a),
    KEY_NUMLOCK     = (0x80+0x45),
    KEY_SCRLCK      = (0x80+0x46),
    KEY_PRTSCR      = (0x80+0x59),
    KEY_HOME        = (0x80+0x47),
    KEY_END         = (0x80+0x4f),
    KEY_PGUP        = (0x80+0x49),
    KEY_PGDN        = (0x80+0x51),
    KEY_INS         = (0x80+0x52),
    KEY_DEL         = (0x80+0x53),
    KEYP_0          = 0,
    KEYP_1          = KEY_END,
    KEYP_2          = KEY_DOWNARROW,
    KEYP_3          = KEY_PGDN,
    KEYP_4          = KEY_LEFTARROW,
    KEYP_5          = '5',
    KEYP_6          = KEY_RIGHTARROW,
    KEYP_7          = KEY_HOME,
    KEYP_8          = KEY_UPARROW,
    KEYP_9          = KEY_PGUP,
    KEYP_DIVIDE     = '/',
    KEYP_PLUS       = '+',
    KEYP_MINUS      = '-',
    KEYP_MULTIPLY   = '*',
    KEYP_PERIOD     = 0,
    KEYP_EQUALS     = KEY_EQUALS,
    KEYP_ENTER      = KEY_ENTER,
};

#endif          // __DOOMKEYS__

