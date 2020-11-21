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
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

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
	0b00010000000000001111u, // I
	0b00100000000010001110u, // J
	0b00110000000000010111u, // L
	0b01000000000000110011u, // sQuare
	0b01010000000000110110u, // S
	0b01100000000000100111u, // T
	0b01110000000011000110u, // Z
};

#define GET_TETRIMINO_ATTRIB(tetrimino) ((tetrimino) >> 16U)

EXTERN_C void draw_tetrimino(MkrTetroidGame* game, tetrimino_bytes tetrimino, unsigned int x_offset, unsigned int y_offset);
EXTERN_C tetrimino_bytes tetrimino_rotate_clockwise(tetrimino_bytes);
EXTERN_C tetrimino_bytes tetrimino_rotate_counterclockwise(tetrimino_bytes);


#endif //_MKR_TETROID_TETRIMINO_H
