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
#ifndef MKR_TETROID_H
#define MKR_TETROID_H

#define BUFFER_WIDTH 80
#define BUFFER_HEIGHT 24

unsigned char read_inputs();

int initialize_screen();

void finalize_screen();

/**
 * Swaps the screen buffer
 */
void refresh_screen();

/**
 * Clears the screen buffer
 */
void clear_screen();

/**
 * Prints a char to the screen buffer
 * \param x coordinate
 * \param y coordinate
 * \param c character
 * \param attrib character attribute
 */
void print_char(int x, int y, char c, char attrib);

#endif