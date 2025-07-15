# Create compatibility library
add_library(compatibility_lib
    CompatibilityCalculator.cpp
    CompatibilityManager.cpp
    CompatibilityTypes.cpp
)

# Create alias for consistent naming
add_library(LoveCompatibilityPlanner::compatibility ALIAS compatibility_lib)

# Set target properties
set_target_properties(compatibility_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Include directories
target_include_directories(compatibility_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
target_link_libraries(compatibility_lib
    PUBLIC
        utils_lib
    PRIVATE
        Threads::Threads
)

# Compiler features
target_compile_features(compatibility_lib
    PUBLIC
        cxx_std_17
)

# Install targets
install(TARGETS compatibility_lib
    EXPORT LoveCompatibilityPlannerTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
