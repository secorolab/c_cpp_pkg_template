cmake_minimum_required(VERSION 3.20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(PackageName)

include(GNUInstallDirs)

set(CMAKE_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

option(ENABLE_DOC "Build documentation" Off)
option(ENABLE_TESTS "Build unit tests" Off)
option(ENABLE_PACKAGE_REGISTRY "Add this package to CMake's package registry" Off)

add_subdirectory(src)

if(ENABLE_TESTS)
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory(test)
endif()

if(ENABLE_DOC)
    # Find Doxygen package
    find_package(Doxygen REQUIRED)

    # Set Doxygen variables
    set(DOXYGEN_GENERATE_HTML YES) # Enable HTML documentation generation
    set(DOXYGEN_GENERATE_XML NO) # Disable XML output (optional, depends on your needs)
    set(DOXYGEN_EXCLUDE "test/*") # Optionally exclude test folders from documentation

    # Set the paths for the input sources and the output directory
    set(DOXYGEN_INPUT_DIR "${CMAKE_SOURCE_DIR}/src") # Path to source code directory
    set(DOXYGEN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include") # Path to include directory
    set(DOXYGEN_README "${CMAKE_SOURCE_DIR}/README.md") # Path to README.md
    set(DOXYGEN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/docs") # Output directory for the docs
    set(HTML_EXTRA_STYLESHEET "${CMAKE_SOURCE_DIR}/docs/styles/doxy.css") # Path to custom CSS
    set(HTML_HEADER "${CMAKE_SOURCE_DIR}/docs/styles/doxy_header.html") # Path to custom header

    # Ensure that the output directory exists
    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

    # Provide path to Doxygen config file
    set(DOXYGEN_CONFIG_FILE "${CMAKE_SOURCE_DIR}/Doxyfile.in") # Path to your Doxygen configuration

    # Check if Doxygen configuration file exists
    if(EXISTS "${DOXYGEN_CONFIG_FILE}")
        message(STATUS "Doxygen config file found: ${DOXYGEN_CONFIG_FILE}")
    else()
        message(FATAL_ERROR "Doxygen config file not found!")
    endif()

    # Modify the Doxyfile variables in the CMakeLists.txt
    configure_file(${CMAKE_SOURCE_DIR}/Doxyfile.in ${CMAKE_BINARY_DIR}/Doxyfile @ONLY)

    # Add custom target to generate docs using Doxygen
    add_custom_target(
        docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
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
