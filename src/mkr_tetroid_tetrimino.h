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

#ifndef MKR_TETROID_TETRIMINO_H
#define MKR_TETROID_TETRIMINO_H

enum Tetrimino {
    TETRIMINO_I = 0,
    TETRIMINO_J,
    TETRIMINO_L,
    TETRIMINO_Q,
    TETRIMINO_S,
    TETRIMINO_T,
    TETRIMINO_Z
};

unsigned int const tetriminos[] = {
	/*
	 * A Tetrimino is defined by a byte,
	 * the upper nibble represents the upper row
	 * and the lower nibble represents the lower row.
	 */
	0b00010000000000001111, // I
	0b00100000000010001110, // J
	0b00110000000000010111, // L
	0b01000000000000110011, // sQuare
	0b01010000000000110110, // S
	0b01100000000000100111, // T
	0b01110000000011000110, // Z
};

#define GET_TETRIMINO_ATTRIB(tetrimino) ((tetrimino) >> 16U)

void draw_tetrimino(unsigned short tetrimino, unsigned int x_offset, unsigned int y_offset);

#endif //_MKR_TETROID_TETRIMINO_H
