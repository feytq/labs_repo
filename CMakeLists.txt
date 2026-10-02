cmake_minimum_required(VERSION 3.10)
project(CourseLabs CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)
endif()

add_subdirectory(aisd/lab1_kommivoyazher)
add_subdirectory(aisd/lab2_bm_search)
add_subdirectory(oop/lab1_prostoy_klass)