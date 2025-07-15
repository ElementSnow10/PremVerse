# Create events library
add_library(events_lib
    EventPlanner.cpp
    EventManager.cpp
    EventTypes.cpp
    EventValidator.cpp
)

# Create alias
add_library(LoveCompatibilityPlanner::events ALIAS events_lib)

# Set target properties
set_target_properties(events_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Include directories
target_include_directories(events_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
target_link_libraries(events_lib
    PUBLIC
        utils_lib
        storage_lib
    PRIVATE
        Threads::Threads
)

# Compiler features
target_compile_features(events_lib
    PUBLIC
        cxx_std_17
)

# Install targets
install(TARGETS events_lib
    EXPORT LoveCompatibilityPlannerTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
