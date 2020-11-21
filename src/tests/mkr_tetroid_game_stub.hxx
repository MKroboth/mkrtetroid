//
// Created by mkr on 21.11.20.
//

#ifndef MKR_TETROID_GAME_STUB_HXX
#define MKR_TETROID_GAME_STUB_HXX
#include "../mkr_tetroid.h"
static inline MkrTetroidGame MkrTetroidGameStub_new() {
    MkrTetroidGame result;
    result.finalize_screen = []{};
    result.clear_screen = []{};
    result.refresh_screen = []{};
    result.initialize_screen = []{ return 1; };
    result.print_char = [](long, long, char, unsigned char){};
    result.read_inputs = []{return (unsigned char)0;};
    return result;
}
#endif //MKR_TETROID_MKR_TETROID_GAME_STUB_HXX
