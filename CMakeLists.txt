cmake_minimum_required(VERSION 3.28)
project(zmqite C)

set(CMAKE_C_STANDARD 11)

find_package(ZeroMQ REQUIRED)
find_package(SQLite3 REQUIRED)

add_library(zmqite SHARED zmqite.c)
target_link_libraries(zmqite SQLite::SQLite3 libzmq)
