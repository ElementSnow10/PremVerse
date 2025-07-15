# Create utils library
add_library(utils_lib
    StringUtils.cpp
    DateUtils.cpp
    MathUtils.cpp
    Logger.cpp
    Configuration.cpp
)

# Create alias
add_library(LoveCompatibilityPlanner::utils ALIAS utils_lib)

# Set target properties
set_target_properties(utils_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Include directories
target_include_directories(utils_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
target_link_libraries(utils_lib
    PRIVATE
        Threads::Threads
)

# Compiler features
target_compile_features(utils_lib
    PUBLIC
        cxx_std_17
)

# Install targets
install(TARGETS utils_lib
    EXPORT LoveCompatibilityPlannerTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
