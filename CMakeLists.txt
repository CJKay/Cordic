################################################################################
# Preliminary setup for building the entire Cordic tree.                       #
################################################################################

cmake_minimum_required(VERSION "3.0")

project("Cordic" VERSION 1.0.0.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include("AddPrefix")

# BUILD_SHARED_LIBS is a standard CMake variable, but we make it visible in the GUI here
set(BUILD_SHARED_LIBS NO CACHE BOOL "If set, shared, instead of static, libraries will be built.")

add_subdirectory("src")
add_prefix(sources "src/" ${sources})
add_library("cordic" ${sources})

target_include_directories("cordic" PUBLIC "include")
target_include_directories("cordic" PUBLIC "include/cordic")

################################################################################
# Configure the CMake config files.                                            #
################################################################################

export(TARGETS "cordic" FILE "${PROJECT_BINARY_DIR}/CordicTargets.cmake")
export(PACKAGE "Cordic")

configure_file("CordicConfig.cmake.in" "${PROJECT_BINARY_DIR}/CordicConfig.cmake" @ONLY)
configure_file("CordicConfigVersion.cmake.in" "${PROJECT_BINARY_DIR}/CordicConfigVersion.cmake" @ONLY)

################################################################################
# Generate a Doxyfile upon request.                                            #
################################################################################

find_package(Doxygen)

if(DOXYGEN_FOUND)
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile" @ONLY)
	add_custom_target(doc "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile" WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}" COMMENT "Generating Doxyfile..." VERBATIM)
endif()
