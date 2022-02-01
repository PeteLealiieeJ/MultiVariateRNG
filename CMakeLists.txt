cmake_minimum_required(VERSION 3.0.2)
project(MultiVariRNG)

find_package( Eigen3 3.3 REQUIRED NO_MODULE)

add_library(
    MultiVariRNG
    src/MultiVariRNG.h
    src/MultiVariRNG.cxx
)

target_link_libraries(
  MultiVariRNG 
  Eigen3::Eigen
)
