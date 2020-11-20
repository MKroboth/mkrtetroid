//
// Created by mkr on 20.11.20.
//

#include "mkr_tetroid.h"
#include "mkr_tetroid_utils.h"

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