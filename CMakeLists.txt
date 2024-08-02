cmake_minimum_required(VERSION 3.10)

enable_testing()

# Necessary to link a subfolder library into another subfolder
cmake_policy(SET CMP0079 NEW)
cmake_policy(SET CMP0076 NEW)

option(EXPORT_COMPILE_COMMANDS "export the compile_commands.json" ON)

# Necessary for clangd to work properly
if(EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

project(Reproducer VERSION 2023.0)

enable_language(C)
enable_language(CXX)

find_package(Python 3.6 REQUIRED COMPONENTS Interpreter Development)
add_subdirectory(extern/pybind11)

pybind11_add_module(buglib  lib.cpp)
target_link_libraries(buglib PUBLIC pybind11::module)
