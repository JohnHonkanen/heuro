cmake_minimum_required(VERSION 3.7)
project(pathfinding-assignment)
set(INCLUDE '${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(SOURCE '${CMAKE_CURRENT_SOURCE_DIR}/src/')

if (MSVC)
include_directories("C:\\Program Files (x86)\\Boost")
#include_directories("C:\\Boost")
#include_directories($ENV{BOOST_INCLUDE_DIR})
include_directories(${INCLUDE})
endif (MSVC)

add_executable(pathfinding-assignment "include/main.cpp")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT pathfinding-assignment)