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
#ifndef MKR_TETROID_CONSOLE_OUT_H
#define MKR_TETROID_CONSOLE_OUT_H
#include <curses.h>

#define MKRT_END endwin
#define MKRT_INIT initscr
#define MKRT_HAS_COLORS has_colors
#define MKRT_ENABLE_COLORS start_color
#define MKRT_INIT_COLOR init_pair

#define MKRT_COLOR_CYAN COLOR_CYAN
#define MKRT_COLOR_BLACK COLOR_BLACK
#define MKRT_COLOR_BROWN COLOR_YELLOW
#define MKRT_COLOR_BLUE COLOR_BLUE
#define MKRT_COLOR_RED COLOR_RED
#define MKRT_COLOR_GREEN COLOR_GREEN
#define MKRT_COLOR_MAGENTA COLOR_MAGENTA
#define MKRT_COLOR_BRIGHT_BIT 8u

#define MKRT_CBREAK cbreak
#define MKRT_NOECHO noecho
#define MKRT_ERASE erase
#define MKRT_MOVE move
#define MKRT_ATTRON attron
#define MKRT_COLOR_PAIR COLOR_PAIR
#define MKRT_ATTROFF attroff
#define MKRT_ADDCH addch
#define MKRT_REFRESH refresh

#endif