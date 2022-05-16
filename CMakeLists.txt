# CMakeList.txt : Top-level CMake project file

cmake_minimum_required (VERSION 3.8)

# Project Name
project ("RayTracer")

find_package(OpenMP)

# C++ Standard Version
set(CMAKE_CXX_STANDARD 20)

######################################
## C++ Compiling Flags
set(CMAKE_CXX_STANDARD 20)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    set(CMAKE_CXX_FLAGS         "")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")          # Debug + Compile Time Optimization
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")             # Runtime Optimization
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    set(CMAKE_CXX_FLAGS         "")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")          # Debug + Compile Time Optimization
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")             # Runtime Optimization
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    set(CMAKE_CXX_FLAGS         "")
    set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -Od -DEBUG")      # Debug + Compile Time Optimization
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG")    # Runtime Optimization
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR})

# Library Directory
add_subdirectory("lib")

file (GLOB RAYTRACER_SOURCES
    main.cpp
    src/*.cpp
)

file (GLOB RAYTRACER_HEADERS
    src/*.hpp
)

add_executable(RayTracer
    ${RAYTRACER_SOURCES}
    ${RAYTRACER_HEADERS}
)

# Linking libraries
target_link_libraries(RayTracer opengl32 glad glfw glm OpenMP::OpenMP_CXX)

# Profiling
set_target_properties(RayTracer PROPERTIES LINK_FLAGS "/PROFILE")

# Including root directory & libraries directories
target_include_directories(RayTracer PUBLIC
    ${PROJECT_SOURCE_DIR}
    $<INSTALL_INTERFACE:include>
)

# Installation Procedure
install(
    TARGETS RayTracer
    CONFIGURATIONS ${CMAKE_CONFIGURATION_TYPES}
)