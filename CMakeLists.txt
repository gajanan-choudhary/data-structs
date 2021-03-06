cmake_minimum_required(VERSION 3.6)

# Project
project(data_structs LANGUAGES CXX)
set(LIBRARY_NAME "data_structs")

# Specify binary and library output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")

#------------------------------------------------------------------------------#
# Build options
option(ENABLE_TESTS "Enable CTest testing" ON)

#------------------------------------------------------------------------------#
# Set CMake modules path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_scripts")
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_SOURCE_DIR}/cmake_scripts")

# Build type
include(CTest)
include(Documentation) # Doxygen
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()
include(BuildType)
if(ENABLE_TESTS)
    include(Doctest)
endif()

#------------------------------------------------------------------------------#
# Location of project header files
include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory(src)
if(ENABLE_TESTS)
    add_subdirectory(tests)
endif() # if(ENABLE_TESTS)

