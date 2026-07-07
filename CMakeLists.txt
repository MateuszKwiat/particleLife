cmake_minimum_required(VERSION 3.15...4.1)

project(
    particleLife
    VERSION 0.1
    DESCRIPTION "Particle Life Simulator"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PROJECT_IS_TOP_LEVEL)

    set(CMAKE_CXX_EXTENSIONS OFF)

    include(CTest)
    include(GoogleTest)

endif()

include(FetchContent)
include(cmake_modules/Coverage.cmake)

add_subdirectory(app)
add_subdirectory(external)
add_subdirectory(src)

if (PROJECT_IS_TOP_LEVEL AND BUILD_TESTING)

    enable_testing()
    add_subdirectory(tests)

endif()
