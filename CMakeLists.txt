cmake_minimum_required(VERSION 3.17)
project(mkr_tetroid C)


add_executable(mkr_tetroid main.c mkr_tetroid.h refresh_screen.c clear_screen.c initialize_screen.c finalize_screen.c print_char.c mkr_tetroid_buffer.h buffer_definition.c read_inputs.c mkr_tetroid_console_out.h)
set(CURSES_NEED_NCURSES FALSE)
find_package(Curses REQUIRED)

set_property(TARGET mkr_tetroid PROPERTY C_STANDARD 90)
target_link_libraries(mkr_tetroid curses)
include_directories(SYSTEM ${CURSES_INCLUDE_DIRS})