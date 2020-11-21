//
// Created by mkr on 20.11.20.
//

#include <catch2/catch.hpp>
#include "../mkr_tetroid_tetrimino.h"

TEST_CASE("get_tetrimino_attrib") {
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_I]) == 0b0001);
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_J]) == 0b0010);
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_L]) == 0b0011);
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_Q]) == 0b0100);
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_S]) == 0b0101);
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_T]) == 0b0110);
    REQUIRE(GET_TETRIMINO_ATTRIB(tetriminos[TETRIMINO_Z]) == 0b0111);
}