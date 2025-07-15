# Create gifts library
add_library(gifts_lib
    GiftSuggester.cpp
    GiftManager.cpp
    GiftCategories.cpp
    GiftPreferences.cpp
)

# Create alias
add_library(LoveCompatibilityPlanner::gifts ALIAS gifts_lib)

# Set target properties
set_target_properties(gifts_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Include directories
target_include_directories(gifts_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
target_link_libraries(gifts_lib
    PUBLIC
        utils_lib
        storage_lib
    PRIVATE
        Threads::Threads
)

# Compiler features
target_compile_features(gifts_lib
    PUBLIC
        cxx_std_17
)

# Install targets
install(TARGETS gifts_lib
    EXPORT LoveCompatibilityPlannerTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
