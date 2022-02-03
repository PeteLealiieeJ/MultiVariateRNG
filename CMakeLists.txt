cmake_minimum_required(VERSION 3.0.2)
project(MultiVariRNG VERSION "1.0.0")
add_definitions(-std=c++17)

add_library(
  MultiVariRNG INTERFACE
)

target_include_directories( MultiVariRNG INTERFACE
  ${PROJECT_SOURCE_DIR}/src/
)

# UNCOMMENT IF YOU WANT TO BUILD EXAMPLES FOLDER
add_subdirectory(examples)