cmake_minimum_required(VERSION 3.30)
project(ac_std)

set(CMAKE_CXX_STANDARD 20)


file(GLOB HEADERS include/* include/*/* include/*/*/*)
file(GLOB SOURCES src/* src/*/* src/*/*/*)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:$CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
  -Wall -Wextra -Werror -Wpedantic -O3
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
