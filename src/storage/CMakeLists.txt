# Create storage library
add_library(storage_lib
    FileManager.cpp
    DataPersistence.cpp
    UserProfile.cpp
    DatabaseConnection.cpp
)

# Create alias
add_library(LoveCompatibilityPlanner::storage ALIAS storage_lib)

# Set target properties
set_target_properties(storage_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Include directories
target_include_directories(storage_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
target_link_libraries(storage_lib
    PUBLIC
        utils_lib
    PRIVATE
        Threads::Threads
)

# Compiler features
target_compile_features(storage_lib
    PUBLIC
        cxx_std_17
)

# Install targets
install(TARGETS storage_lib
    EXPORT LoveCompatibilityPlannerTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
