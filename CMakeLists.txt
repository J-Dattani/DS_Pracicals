cmake_minimum_required(VERSION 3.10)
project(practicals C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "src/*.c")

foreach(source_file ${SOURCES})
    get_filename_component(file_name ${source_file} NAME_WE)
    add_executable(${file_name} ${source_file})
endforeach()
