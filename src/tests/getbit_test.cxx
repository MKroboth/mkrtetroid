//
// Created by mkr on 20.11.20.
//

#include "gtest/gtest.h"
#include "../mkr_tetroid_utils.h"

TEST(getbit, check01010101) {
    unsigned char bits[] =
	    { 0, 1, 0, 1, 0, 1, 0, 1};
    unsigned value = 0b0101'0101;

    for (int i = 0 ; i < sizeof(bits); ++i) {
	EXPECT_EQ(GET_NTH_BIT(value, i), bits[sizeof(bits) - 1 - i]);
    }
}
TEST(getbit, check10101010) {
    unsigned char bits[] =
	    { 1, 0, 1, 0, 1, 0, 1, 0};
    unsigned value = 0b1010'1010;

    for (int i = 0 ; i < sizeof(bits); ++i) {
	EXPECT_EQ(GET_NTH_BIT(value, i), bits[sizeof(bits) - 1 - i]);
    }
}
TEST(getbit, check00110011) {
    unsigned char bits[] =
	    { 0, 0, 1, 1, 0, 0, 1, 1};
    unsigned value = 0b001'10011;

    for (int i = 0 ; i < sizeof(bits); ++i) {
	EXPECT_EQ(GET_NTH_BIT(value, i), bits[sizeof(bits) - 1 - i]);
    }
}
TEST(getbit, check11001100) {
    unsigned char bits[] =
	    { 1, 1, 0, 0, 1, 1, 0, 0};
    unsigned value = 0b110'01100;

    for (int i = 0 ; i < sizeof(bits); ++i) {
	EXPECT_EQ(GET_NTH_BIT(value, i), bits[sizeof(bits) - 1 - i]);
    }
}