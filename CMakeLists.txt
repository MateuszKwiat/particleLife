cmake_minimum_required(VERSION 3.15...4.1)

project(
    particleLife
    VERSION 0.1
    DESCRIPTION "Particle Life Simulator"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)

    include(CTest)
    include(GoogleTest)
endif()

include(FetchContent)

add_subdirectory(app)
add_subdirectory(external)
add_subdirectory(src)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
