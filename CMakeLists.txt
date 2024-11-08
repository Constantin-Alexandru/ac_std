cmake_minimum_required(VERSION 3.30)
project(ac_std)

set(CMAKE_CXX_STANDARD 20)


file(GLOB HEADERS include/* include/*/* include/*/*/*)
file(GLOB SOURCES src/* src/*/* src/*/*/*)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${HEADERS}
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
  -Wall -Wextra -Werror -Wpedantic -O3
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
