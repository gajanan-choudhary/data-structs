list(APPEND src_sources
    vector.cpp
)

list(REMOVE_DUPLICATES src_sources)

add_library(src_sources_obj OBJECT EXCLUDE_FROM_ALL ${src_sources})
add_library("${LIBRARY_NAME}" STATIC $<TARGET_OBJECTS:src_sources_obj>)

