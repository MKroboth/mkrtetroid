//
// Created by mkr on 20.11.20.
//

#include "mkr_tetroid.h"
#include "mkr_tetroid_tetrimino.h"
#include "mkr_tetroid_utils.h"

#define BITS_PER_ROW (4U)
#define ROWS_PER_TETRIMINO (4U)
#define COLS_PER_TETRIMINO (4U)



void draw_tetrimino(unsigned short tetrimino, unsigned int x_offset, unsigned int y_offset) {
    unsigned int x;
    unsigned int y;
    unsigned char bit;
    unsigned char attrib;

    attrib = GET_TETRIMINO_ATTRIB(tetrimino);


    for(y = 0; y < COLS_PER_TETRIMINO; ++y) {
	for (x = 0 ; x < ROWS_PER_TETRIMINO ; ++x) {
	    bit = GET_NTH_BIT(tetrimino, (y * BITS_PER_ROW + x));

	    if(bit == 1) {
		print_char(y+y_offset, x+x_offset, 'X', attrib);
	    }
	}
    }
}

