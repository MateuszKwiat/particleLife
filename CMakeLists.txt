cmake_minimum_required(VERSION 3.15...4.1)

project(
    particleLife
    VERSION 0.1
    DESCRIPTION "Particle Life Simulator"
    LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)

    include(GoogleTest)
endif()

# include(FetchContent)
add_subdirectory(src)
add_subdirectory(app)
