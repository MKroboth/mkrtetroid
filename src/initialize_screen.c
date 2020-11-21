//
// Created by mkr on 19.11.20.
//
#include "mkr_tetroid.h"
#include "mkr_tetroid_console_out.h"
/*
   Copyright (c) 2020 Maximilian Kroboth <mkr at kroboth minus home dot at>.
   This file is part of mkr-tetroid.
   mkr-tetroid is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   mkr-tetroid is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with mkr-tetroid.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "mkr_tetroid.h"
int initialize_screen() {
    MKRT_INIT();
    if(MKRT_HAS_COLORS() == FALSE) {
	MKRT_END();
	fprintf(stderr, "Your terminal does not support color\n");
	return FALSE;
    }

    MKRT_ENABLE_COLORS();

    MKRT_INIT_COLOR(1, MKRT_COLOR_CYAN, MKRT_COLOR_BLACK); // I
    MKRT_INIT_COLOR(2, MKRT_COLOR_BLUE, MKRT_COLOR_BLACK); // J
    MKRT_INIT_COLOR(3, MKRT_COLOR_BROWN, MKRT_COLOR_BLACK); // L
    MKRT_INIT_COLOR(4, MKRT_COLOR_BRIGHT_BIT | MKRT_COLOR_BROWN, MKRT_COLOR_BLACK); // Q
    MKRT_INIT_COLOR(5, MKRT_COLOR_GREEN, MKRT_COLOR_BLACK); // S
    MKRT_INIT_COLOR(6, MKRT_COLOR_MAGENTA, MKRT_COLOR_BLACK); // T
    MKRT_INIT_COLOR(7, MKRT_COLOR_RED, MKRT_COLOR_BLACK); // Z

    MKRT_CBREAK();
    MKRT_NOECHO();

    MKRT_ERASE();
    return TRUE;
}
