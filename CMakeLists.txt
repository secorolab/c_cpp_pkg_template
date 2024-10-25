cmake_minimum_required(VERSION 3.20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(PackageName)

include(GNUInstallDirs)

set(CMAKE_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

option(ENABLE_TESTS "Build unit tests" Off)
option(ENABLE_PACKAGE_REGISTRY "Add this package to CMake's package registry" Off)

add_subdirectory(src)

if(ENABLE_TESTS)
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory(test)
endif()

# Export this package to CMake's package registry
if(ENABLE_PACKAGE_REGISTRY)
    export(PACKAGE ${PROJECT_NAME})
endif()

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${PROJECT_NAME}-config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_DIR})

# Generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
    VERSION "0.1.0"
    COMPATIBILITY AnyNewerVersion)

# Install cmake configuration and package version
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
        DESTINATION ${CMAKE_INSTALL_DIR})

# Make the targets accessible from this packages's build tree
export(
    EXPORT ${PROJECT_NAME}-targets
    NAMESPACE ${PROJECT_NAME}::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake")

# Make the targets accessible from this packages's install tree
install(
    EXPORT ${PROJECT_NAME}-targets
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_DIR})

# Install all public header files
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp")
