cmake_minimum_required(VERSION 3.10)
project(btc
        VERSION 0.0.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
add_compile_options(-Wall -Wextra -Werror)

#include_directories(ex00)

# submoduls of ex00
add_subdirectory(ex00)
add_subdirectory()
add_subdirectory()
