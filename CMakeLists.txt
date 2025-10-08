cmake_minimum_required(VERSION 3.10...3.31)
project(adeqmath
  VERSION 0.0.1
  LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(${PROJECT_NAME}
  src/op.c
  src/scalar.c
  src/vector.c
)

target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/include/
)
