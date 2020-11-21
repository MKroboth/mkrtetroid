cmake_minimum_required(VERSION 3.17)
project(mkr_tetroid C CXX)


set(MKR_TETROID_SOURCES
        src/mkr_tetroid.h
        src/refresh_screen.c
        src/clear_screen.c
        src/initialize_screen.c
        src/finalize_screen.c
        src/print_char.c
        src/mkr_tetroid_buffer.h
        src/buffer_definition.c
        src/read_inputs.c
        src/mkr_tetroid_console_out.h
        src/mkr_tetroid_tetrimino.h
        src/draw_tetrimino.c
        src/mkr_tetroid_utils.h)
set(MKR_TETROID_TEST_SOURCES
        src/tests/test_config.cxx
        src/tests/getbit_test.cxx)

add_executable(mkr_tetroid src/main.c ${MKR_TETROID_SOURCES})
set(CURSES_NEED_NCURSES FALSE)
find_package(Curses REQUIRED)

set_property(TARGET mkr_tetroid PROPERTY C_STANDARD 90 PROPERTY C_EXTENSIONS TRUE)
target_link_libraries(mkr_tetroid curses)
include_directories(SYSTEM ${CURSES_INCLUDE_DIRS})


Include(FetchContent)

include_directories(CTest)

find_package(Catch2 REQUIRED)
include(Catch)

add_executable(mkr_tetroid_UnitTests
        ${MKR_TETROID_TEST_SOURCES}
        ${MKR_TETROID_SOURCES}
        )

target_link_libraries(mkr_tetroid_UnitTests curses Catch2::Catch2)
catch_discover_tests(mkr_tetroid_UnitTests)
add_test(mkr_tetroid_UnitTests NAME runUnitTests COMMAND runUnitTests)


