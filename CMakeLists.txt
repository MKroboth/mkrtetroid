cmake_minimum_required(VERSION 3.17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

project(mkr_tetroid C CXX)
enable_testing()
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

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
        src/mkr_tetroid_utils.h src/mkr_tetroid.c)
set(MKR_TETROID_TEST_SOURCES
        src/tests/test_config.cxx
        src/tests/getbit_test.cxx
        src/tests/get_tetrimino_attrib_test.cxx src/tests/draw_tetrimino_test.cxx src/tests/mkr_tetroid_game_stub.hxx)

add_executable(mkr_tetroid src/main.c ${MKR_TETROID_SOURCES})
set(CURSES_NEED_NCURSES FALSE)
find_package(Curses REQUIRED)

set_property(TARGET mkr_tetroid PROPERTY C_STANDARD 90 PROPERTY C_EXTENSIONS TRUE)
target_link_libraries(mkr_tetroid curses)
include_directories(SYSTEM ${CURSES_INCLUDE_DIRS})





add_executable(mkr_tetroid_UnitTests
        ${MKR_TETROID_TEST_SOURCES}
        ${MKR_TETROID_SOURCES}
        )
target_link_libraries(mkr_tetroid_UnitTests curses Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(mkr_tetroid_UnitTests)


