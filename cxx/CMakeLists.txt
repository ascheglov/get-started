cmake_minimum_required(VERSION 2.8.12)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(crc32)

if(MSVC)
    add_definitions(/W4 /WX)
else()
    add_definitions(-std=c++11 -Wall -pedantic -Werror)
endif()

# include paths will start from the root directory
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(calc_crc32)
add_subdirectory(crc32)
