set( CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/examples/bin
    )

###################################################

add_executable(example1 example1.cxx)

target_link_libraries(
  example1
  MultiVariRNG
  Eigen3::Eigen
)

target_include_directories(example1 PUBLIC 
  ${CMAKE_SOURCE_DIR}/src 
)

###################################################

add_executable(example2 example2.cxx)

target_link_libraries(
  example2
  MultiVariRNG
  Eigen3::Eigen
)

target_include_directories(example2 PUBLIC 
  ${CMAKE_SOURCE_DIR}/src 
)