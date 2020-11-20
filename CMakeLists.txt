cmake_minimum_required(VERSION 3.17)
project(mkr_tetroid C CXX)


add_executable(mkr_tetroid src/main.c src/mkr_tetroid.h src/refresh_screen.c src/clear_screen.c src/initialize_screen.c src/finalize_screen.c src/print_char.c src/mkr_tetroid_buffer.h src/buffer_definition.c src/read_inputs.c src/mkr_tetroid_console_out.h src/mkr_tetroid_tetrimino.h src/draw_tetrimino.c src/tests/getbit_test.cxx src/mkr_tetroid_utils.h)
set(CURSES_NEED_NCURSES FALSE)
find_package(Curses REQUIRED)

set_property(TARGET mkr_tetroid PROPERTY C_STANDARD 90 PROPERTY C_EXTENSIONS TRUE)
target_link_libraries(mkr_tetroid curses)
include_directories(SYSTEM ${CURSES_INCLUDE_DIRS})

include_directories(CTest)
add_subdirectory(src/tests)

