cmake_minimum_required(VERSION 3.28)
project(zmqite C)

set(CMAKE_C_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(ZeroMQ REQUIRED)
find_package(czmq REQUIRED)
IF (CZMQ_FOUND)
    include_directories(${CZMQ_INCLUDE_DIRS})
    list(APPEND MORE_LIBRARIES ${CZMQ_LIBRARIES})
ELSE (CZMQ_FOUND)
    message( FATAL_ERROR "czmq not found." )
ENDIF (CZMQ_FOUND)

find_package(SQLite3 REQUIRED)

add_library(zmqite SHARED zmqite.c)
target_link_libraries(zmqite SQLite::SQLite3 ${CZMQ_LIBRARIES} libzmq)
