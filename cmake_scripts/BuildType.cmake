#------------------------------------------------------------------------------#
# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()

# guard against bad build-type strings
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

#------------------------------------------------------------------------------#
# Build type
if(NOT CMAKE_BUILD_TYPE MATCHES "^(|Debug|Release|RelWithDebInfo|MinSizeRel)$")
  message(FATAL_ERROR "CMAKE_BUILD_TYPE parameter should be left empty or set to Debug (-D_DEBUG -g), Release, or RelWithDebInfo (-g).")
endif()
if(CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions(-D_DEBUG -g)
elseif(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
  add_definitions(-g)
endif()

# Determine what level of debugging we are using
set(BUILD_DEBUG_LEVEL "2" CACHE STRING
  "0: None  1: -g  2: -g + _DEBUG  3: Level 2 + Temporary  4: Level 2 + Kitchen Sink  5: All Debugging on")
# Determine if we are using some debugging so that debuggers can show the code
if(BUILD_DEBUG_LEVEL LESS 0 OR BUILD_DEBUG_LEVEL GREATER 3)
  message(FATAL_ERROR "BUILD_DEBUG_LEVEL parameter must be an integer value of the range 0 to 5, inclusive.")
elseif(BUILD_DEBUG_LEVEL EQUAL 1)
  add_definitions(-g)
# Determine if we are using the memory checking debugging
elseif(BUILD_DEBUG_LEVEL EQUAL 2)
  add_definitions(-D_DEBUG -g)
# Determine if we are using temporary user-defined debug functions
elseif(BUILD_DEBUG_LEVEL EQUAL 3)
  add_definitions(-D_DEBUG_TEMPORARY -D_DEBUG -g)
endif()

# Check whether the build type and debug level are consistent
if((BUILD_DEBUG_LEVEL EQUAL 0 AND CMAKE_BUILD_TYPE MATCHES "^(Debug|RelWithDebInfo)$") 
OR (BUILD_DEBUG_LEVEL GREATER 0 AND CMAKE_BUILD_TYPE MATCHES "^(Release|MinSizeRel)$"))
  message(FATAL_ERROR "BUILD_DEBUG_LEVEL is inconsistent with CMAKE_BUILD_TYPE; both parameters should include or exclude debug definitions.")
endif()
