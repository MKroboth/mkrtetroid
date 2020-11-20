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

#include "mkr_tetroid_tetrimino.h"


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
