cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

project(template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(FETCHCONTENT_QUIET OFF)

include(FetchContent)

FetchContent_Declare(
    sfml
    URL https://www.sfml-dev.org/files/SFML-2.4.2-sources.zip
)

FetchContent_GetProperties(sfml)

if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    set(BUILD_SHARED_LIBS TRUE)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

include_directories(
    ${sfml_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(
    game
    src/main.cpp
)

target_link_libraries(game sfml-graphics sfml-system sfml-window)