cmake_minimum_required(VERSION 3.0.0)
project(fraction-math VERSION 0.1.0)

file(GLOB code_src
    "src/*.cc"
)

add_executable(fraction-math ${code_src})

target_include_directories(fraction-math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})