//
// Created by mkr on 20.11.20.
//

#include <catch2/catch.hpp>
#include "../mkr_tetroid_utils.h"

TEST_CASE("getbit") {
    SECTION("check01010100") {
	unsigned char bits[] =
		{0, 1, 0, 1, 0, 1, 0, 1};
	unsigned value = 0b0101'0101;

	for (int i = 0 ; i < sizeof(bits) ; ++i) {
	    REQUIRE(GET_NTH_BIT(value, i) == bits[sizeof(bits) - 1 - i]);
	}
    }
    SECTION("check10101010") {
	unsigned char bits[] =
		{1, 0, 1, 0, 1, 0, 1, 0};
	unsigned value = 0b1010'1010;

	for (int i = 0 ; i < sizeof(bits) ; ++i) {
	    REQUIRE(GET_NTH_BIT(value, i) == bits[sizeof(bits) - 1 - i]);
	}
    }
    SECTION("check00110011") {
	unsigned char bits[] =
		{0, 0, 1, 1, 0, 0, 1, 1};
	unsigned value = 0b001'10011;

	for (int i = 0 ; i < sizeof(bits) ; ++i) {
	    REQUIRE(GET_NTH_BIT(value, i) == bits[sizeof(bits) - 1 - i]);
	}
    }
    SECTION("check11001100") {
	unsigned char bits[] =
		{1, 1, 0, 0, 1, 1, 0, 0};
	unsigned value = 0b110'01100;

	for (int i = 0 ; i < sizeof(bits) ; ++i) {
	    REQUIRE(GET_NTH_BIT(value, i) == bits[sizeof(bits) - 1 - i]);
	}
    }
}