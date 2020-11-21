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
#include "mkr_tetroid.h"
enum Tetrimino {
    TETRIMINO_I = 0,
    TETRIMINO_J,
    TETRIMINO_L,
    TETRIMINO_Q,
    TETRIMINO_S,
    TETRIMINO_T,
    TETRIMINO_Z
};

typedef unsigned int tetrimino_bytes;

tetrimino_bytes const tetriminos[] = {
	/*
	 * A Tetrimino is defined by a byte,
	 * the upper nibble represents the upper row
	 * and the lower nibble represents the lower row.
	 */
	0b000100001111, // I
	0b001010001110, // J
	0b001100010111, // L
	0b010000110011, // sQuare
	0b010100110110, // S
	0b011000100111, // T
	0b011111000110, // Z
};

void draw_tetrimino(MkrTetroidGame* game, tetrimino_bytes tetrimino, unsigned int x_offset, unsigned int y_offset);

#endif //_MKR_TETROID_TETRIMINO_H
