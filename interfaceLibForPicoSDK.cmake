## Include this file if you want to use the snappy-c library
## in YOUR (Pico) project.

cmake_minimum_required(VERSION 3.12)

# Define the snappyc library
add_library(snappyc INTERFACE)

target_sources(snappyc INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/snappy.c
    ${CMAKE_CURRENT_LIST_DIR}/util.c
)

target_include_directories(snappyc INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/
)
