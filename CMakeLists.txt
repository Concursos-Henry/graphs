cmake_minimum_required(VERSION 3.27)
project(graphs C)

set(CMAKE_C_STANDARD 11)

add_executable(chained src/chained.c)
add_executable(matrix src/matrix.c)