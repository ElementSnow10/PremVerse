# CMake minimum version
cmake_minimum_required(VERSION 3.16)

# Project definition
project(PremVerse
    VERSION 1.0.0
    DESCRIPTION "Love Compatibility and Event Planner Application"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Global compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

# Build configuration
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug/Release)")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add custom module path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Options
option(BUILD_TESTS "Build test executables" ON)
option(BUILD_DOCS "Build documentation" OFF)
option(USE_CONAN "Use Conan for dependency management" OFF)

# Find packages
find_package(Threads REQUIRED)

# Include subdirectories
add_subdirectory(src)

# Testing setup
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Documentation
if(BUILD_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        add_subdirectory(docs)
    endif()
endif()

# Install configuration
include(GNUInstallDirs)
install(TARGETS love_compatibility_planner
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Package configuration
set(CPACK_PACKAGE_NAME "LoveCompatibilityPlanner")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
include(CPack)
