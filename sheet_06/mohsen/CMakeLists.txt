cmake_minimum_required(VERSION 3.9)
project(arcade_sh06 C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(arcade_sh06 main.c includes/lineitem_tbl.h src/lineitem_tbl.c)