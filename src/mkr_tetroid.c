//
// Created by mkr on 21.11.20.
//
#include "mkr_tetroid.h"

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
void print_char(long x, long y, char c, unsigned char attrib);

MkrTetroidGame MkrTetroidGame_new() {
    MkrTetroidGame result;
    result.read_inputs = read_inputs;
    result.print_char = print_char;
    result.initialize_screen = initialize_screen;
    result.refresh_screen = refresh_screen;
    result.finalize_screen = finalize_screen;
    result.clear_screen = clear_screen;
    return result;
}

