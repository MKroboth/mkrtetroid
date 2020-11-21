//
// Created by mkr on 21.11.20.
//
#include <catch2/catch.hpp>
#include "../mkr_tetroid_tetrimino.h"
#include "mkr_tetroid_game_stub.hxx"
#include <cstring>
#include <sstream>

constexpr int BUF_WIDTH = 4;
constexpr int BUF_HEIGHT = 4;
static unsigned short buffer[BUF_WIDTH * BUF_HEIGHT];

static inline void clear_buffer() {
    memset(buffer, 0x002E, BUF_WIDTH * BUF_HEIGHT * sizeof(unsigned short));
}

static inline std::string buffer2string(const unsigned short buffer[BUF_WIDTH * BUF_HEIGHT]) {
    std::stringstream sstream;
    for (int x = 0 ; x < BUF_WIDTH ; ++x) {
	for (int y = 0 ; y < BUF_HEIGHT ; ++y) {
	    sstream << (char) (buffer[x * BUF_HEIGHT + y] & 0x00FFu);
	}
	sstream << '\n';
    }
    return sstream.str();
}

static inline std::string buffer2string(const char buffer[BUF_WIDTH * BUF_HEIGHT]) {
    std::stringstream sstream;
    for (int x = 0 ; x < BUF_WIDTH ; ++x) {
	for (int y = 0 ; y < BUF_HEIGHT ; ++y) {
	    sstream << (buffer[x * BUF_HEIGHT + y]);
	}
	sstream << '\n';
    }
    return sstream.str();
}

static void mock_print_char(long x, long y, char ch, unsigned char attrib) {
    buffer[x * BUF_HEIGHT + y] = ((unsigned short) (ch)) | (((unsigned short) attrib) << 8u);
}

static inline void check_tetrimino(char const expected[17]) {
    for (int x = 0 ; x < BUF_WIDTH ; ++x) {
	for (int y = 0 ; y < BUF_HEIGHT ; ++y) {
	    INFO("X: " + std::to_string(x) + ", Y: " + std::to_string(y) + "\n EXPECTED: \n" +
		 buffer2string(expected) + "\n GIVEN: \n" + buffer2string(buffer));
	    REQUIRE(expected[x * BUF_HEIGHT + y] == (buffer[x * BUF_HEIGHT + y] & 0x00FFu));
	}
    }
}

TEST_CASE("draw_tetrimino") {
    MkrTetroidGame game = MkrTetroidGameStub_new();
    memset(buffer, 0, sizeof(buffer));
    game.print_char = mock_print_char;

    SECTION("Check I Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_I], 0, 0);
	check_tetrimino(
		"XXXX"
		"...."
		"...."
		"...."
	);
    }
    SECTION("Check Z Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_Z], 0, 0);
	check_tetrimino(".XX."
			"..XX"
			"...."
			"...."
	);
    }
    SECTION("Check S Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_S], 0, 0);
	check_tetrimino(
		".XX."
		"XX.."
		"...."
		"...."
	);
    }
    SECTION("Check Square Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_Q], 0, 0);
	check_tetrimino(
		"XX.."
		"XX.."
		"...."
		"...."
	);
    }
    SECTION("Check T Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_T], 0, 0);
	check_tetrimino(
		"XXX."
		".X.."
		"...."
		"...."
	);
    }
    SECTION("Check L Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_L], 0, 0);
	check_tetrimino(
		"XXX."
		"X..."
		"...."
		"...."
	);
    }
    SECTION("Check J Tetrimino") {
	clear_buffer();
	draw_tetrimino(&game, tetriminos[TETRIMINO_J], 0, 0);
	check_tetrimino(
		".XXX"
		"...X"
		"...."
		"...."
	);
    }
}

TEST_CASE("rotate tetrimino clockwise") {
    FAIL("TODO");
    MkrTetroidGame game = MkrTetroidGameStub_new();
    memset(buffer, 0, sizeof(buffer));
    game.print_char = mock_print_char;

    SECTION("Check I Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_I]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XXXX"
		"...."
		"...."
		"...."
	);
    }
    SECTION("Check Z Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_Z]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(".XX."
			"..XX"
			"...."
			"...."
	);
    }
    SECTION("Check S Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_S]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		".XX."
		"XX.."
		"...."
		"...."
	);
    }
    SECTION("Check Square Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_Q]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XX.."
		"XX.."
		"...."
		"...."
	);
    }
    SECTION("Check T Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_T]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XXX."
		".X.."
		"...."
		"...."
	);
    }
    SECTION("Check L Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_L]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XXX."
		"X..."
		"...."
		"...."
	);
    }
    SECTION("Check J Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_clockwise(tetriminos[TETRIMINO_J]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		".XXX"
		"...X"
		"...."
		"...."
	);
    }

}

TEST_CASE("rotate tetrimino counterclockwise") {
    FAIL("TODO");
    MkrTetroidGame game = MkrTetroidGameStub_new();
    memset(buffer, 0, sizeof(buffer));
    game.print_char = mock_print_char;


    SECTION("Check I Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_I]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XXXX"
		"...."
		"...."
		"...."
	);
    }
    SECTION("Check Z Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_Z]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(".XX."
			"..XX"
			"...."
			"...."
	);
    }
    SECTION("Check S Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_S]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		".XX."
		"XX.."
		"...."
		"...."
	);
    }
    SECTION("Check Square Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_Q]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XX.."
		"XX.."
		"...."
		"...."
	);
    }
    SECTION("Check T Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_T]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XXX."
		".X.."
		"...."
		"...."
	);
    }
    SECTION("Check L Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_L]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		"XXX."
		"X..."
		"...."
		"...."
	);
    }
    SECTION("Check J Tetrimino") {
	clear_buffer();
	tetrimino_bytes result = tetrimino_rotate_counterclockwise(tetriminos[TETRIMINO_J]);
	draw_tetrimino(&game, result, 0, 0);
	check_tetrimino(
		".XXX"
		"...X"
		"...."
		"...."
	);
    }

}