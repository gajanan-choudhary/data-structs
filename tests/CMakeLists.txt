cmake_minimum_required(VERSION 3.6)

# List all files containing tests.
list(APPEND tests_sources
    main.cpp
)
list(REMOVE_DUPLICATES tests_sources)

list(APPEND lib_depends ${LIBRARY_NAME})

set(TEST_MAIN unit_tests)
set(TEST_RUNNER_PARAMS "")

add_executable(${TEST_MAIN} ${tests_sources})
target_link_libraries(${TEST_MAIN} PRIVATE ${lib_depends})
#set_target_properties(${TEST_MAIN} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
#target_set_warnings(${TEST_MAIN} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).

set_target_properties(${TEST_MAIN} PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED YES 
    CXX_EXTENSIONS NO
)

add_test(
    NAME ${LIBRARY_NAME}.${TEST_MAIN}
    COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS}
)
