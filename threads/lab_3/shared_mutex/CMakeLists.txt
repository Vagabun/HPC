cmake_minimum_required(VERSION 3.12)
project(shared_mutex)

set(CMAKE_CXX_STANDARD 11)

add_executable(shared_mutex main.cpp src/shared_mutex.cpp src/shared_mutex.h)