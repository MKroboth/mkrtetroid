cmake_minimum_required(VERSION 3.17)
project(mkr_tetroid C CXX)


add_executable(mkr_tetroid src/main.c src/mkr_tetroid.h src/refresh_screen.c src/clear_screen.c src/initialize_screen.c src/finalize_screen.c src/print_char.c src/mkr_tetroid_buffer.h src/buffer_definition.c src/read_inputs.c src/mkr_tetroid_console_out.h src/mkr_tetroid_tetrimino.h src/draw_tetrimino.c src/tests/getbit_test.cxx src/mkr_tetroid_utils.h)
set(CURSES_NEED_NCURSES FALSE)
find_package(Curses REQUIRED)

set_property(TARGET mkr_tetroid PROPERTY C_STANDARD 90 PROPERTY C_EXTENSIONS TRUE)
target_link_libraries(mkr_tetroid curses)
include_directories(SYSTEM ${CURSES_INCLUDE_DIRS})

include_directories(CTest)
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)


include_directories("${gtest_SOURCE_DIR}/include")


add_subdirectory(src/tests)

