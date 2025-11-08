cmake_minimum_required(VERSION 3.28.3)
project(particle_life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

add_subdirectory(./src/app)
add_subdirectory(./src/core)
add_subdirectory(./src/render)
add_subdirectory(./src/ui)
add_subdirectory(./tests/)
