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
#include "mkr_tetroid_buffer.h"
#include "mkr_tetroid_console_out.h"

void refresh_screen() {
    unsigned int x; //!< X coordinate.
    unsigned int y; //!< Y coordinate.

    MKRT_ERASE();

    for (x = 0 ; x < BUFFER_WIDTH ; ++x) {
	for (y = 0 ; y < BUFFER_HEIGHT ; ++y) {
	  MKRT_MOVE(x, y);
	  MKRT_ATTRON(MKRT_COLOR_PAIR(buffer[x][y].attrib));
	  MKRT_ADDCH(buffer[x][y].content);
	  MKRT_ATTROFF(MKRT_COLOR_PAIR(buffer[x][y].attrib));
	}
    }

    MKRT_REFRESH();
}
