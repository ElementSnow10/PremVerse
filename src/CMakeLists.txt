# Main executable
add_executable(love_compatibility_planner main.cpp)

# Add subdirectories for each module
add_subdirectory(compatibility)
add_subdirectory(events)
add_subdirectory(gifts)
add_subdirectory(storage)
add_subdirectory(utils)

# Link libraries to main executable
target_link_libraries(love_compatibility_planner
    PRIVATE
        compatibility_lib
        events_lib
        gifts_lib
        storage_lib
        utils_lib
        Threads::Threads
)

# Set target properties
set_target_properties(love_compatibility_planner PROPERTIES
    OUTPUT_NAME "love_planner"
    DEBUG_POSTFIX "_debug"
)

# Compiler-specific settings
target_compile_features(love_compatibility_planner
    PRIVATE
        cxx_std_17
)

# Include directories
target_include_directories(love_compatibility_planner
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}
)

