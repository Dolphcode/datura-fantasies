cmake_minimum_required(VERSION 3.20)
project(datura-fantasies)

# Set the option to use the source or the package
option(GLFW_USE_SUBMOD "Default behavior on MSVC, alt behavior on Linux" OFF)

# Include glfw
if (MSVC OR GLFW_USE_SUBMOD)
	add_subdirectory(external/glfw)
elseif(LINUX)
	find_package(glfw3 REQUIRED)
endif()

# Find the OpenGL package
find_package(OpenGL REQUIRED)

# Build other submodules for external dependencies (i.e. imgui)

# Get all source files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.c)

add_executable(datura-fantasies)
target_sources(datura-fantasies PRIVATE ${SOURCE_FILES})
target_include_directories(datura-fantasies PRIVATE include)
target_link_libraries(datura-fantasies glfw)
target_link_libraries(datura-fantasies OpenGL::GL)

