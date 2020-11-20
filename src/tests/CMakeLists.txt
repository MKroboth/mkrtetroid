find_package(GTest REQUIRED)
add_executable(mkr_tetroid_UnitTests
        getbit_test.cxx
        ../buffer_definition.c
        ../clear_screen.c
        ../draw_tetrimino.c
        ../finalize_screen.c
        ../initialize_screen.c
        ../print_char.c
        ../read_inputs.c
        ../refresh_screen.c
)
include_directories(${GTEST_INCLUDE_DIR} ..)

target_link_libraries(mkr_tetroid_UnitTests curses ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
add_test(mkr_tetroid_UnitTests NAME runUnitTests COMMAND runUnitTests)