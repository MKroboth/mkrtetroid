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
#include <stdlib.h>
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
unsigned short tetriminos[] = {
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


#define GET_NTH_BIT(byte, idx) (byte >> idx) & 1

void draw_tetrimino(unsigned short tetrimino, unsigned int x_offset, unsigned int y_offset) {
    unsigned int x;
    unsigned int y;
    unsigned char row;
    unsigned char bit;
    unsigned char attrib;

    attrib = tetrimino >> 8U;


    for(y = 0; y < 2; ++y) {
	for (x = 0 ; x < 4 ; ++x) {
	    bit = GET_NTH_BIT(tetrimino, (y * 4 + x));

	    if(bit == 1) {
		print_char(y+y_offset, x+x_offset, 'X', attrib);
	    }
	}
    }
}

int simple_show_pieces_run() {
    unsigned char input = read_inputs();
    draw_tetrimino(tetriminos[TETRIMINO_I], 2, 10);
    draw_tetrimino(tetriminos[TETRIMINO_J], 6, 10);
    draw_tetrimino(tetriminos[TETRIMINO_Q], 8, 14);
    draw_tetrimino(tetriminos[TETRIMINO_S], 2, 20);
    draw_tetrimino(tetriminos[TETRIMINO_Z], 6, 20);
    draw_tetrimino(tetriminos[TETRIMINO_T], 12, 20);
    draw_tetrimino(tetriminos[TETRIMINO_L], 12, 10);
    return (input & 0b10000000u) == 0; // Check if high bit is set.
}

int run() {
    return simple_show_pieces_run();
}

int main() {
    int is_alive;

    if(!initialize_screen()) {
        // Our screen is not capable for showing the buffer.

        return 1;
    }
    atexit(finalize_screen);

    do {
	clear_screen();
	is_alive = run();
	refresh_screen();
    } while (is_alive);
    return 0;
}
