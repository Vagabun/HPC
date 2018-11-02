cmake_minimum_required(VERSION 3.12)
project(hierarchical_mutex)

set(CMAKE_CXX_STANDARD 14)

add_executable(hierarchical_mutex main.cpp src/hierarchical_mutex.cpp src/hierarchical_mutex.h)