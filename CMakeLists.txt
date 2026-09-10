cmake_minimum_required(VERSION 4.0)

project(
  Calculator
  VERSION 0.0.1
  LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


file(GLOB SRC_FILES "src/*.c")
add_executable(
  calculator ${SRC_FILES}
)

target_include_directories(
  calculator
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(
  calculator
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
)