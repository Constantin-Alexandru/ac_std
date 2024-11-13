cmake_minimum_required(VERSION 3.30)
project(ac_std)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file(GLOB SOURCES src/*.cpp src/*/*.cpp src/*/*/*.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
  PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_CURRENT_SOURCE_DIR}/include/ac_std
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
  -Wall -Wextra -Werror -Wpedantic -O3
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

