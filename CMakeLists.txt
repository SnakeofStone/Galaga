cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(GalagaProject VERSION 0.1)

add_subdirectory(src)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sfml 
    ${CMAKE_CURRENT_LIST_DIR}/sfml/build)

set(SFML_STATIC_LIBRARIES TRUE)
set(BUILD_SHARED_LIBS FALSE)
set(SFML_DIR ${CMAKE_CURRENT_LIST_DIR}/sfml/build)

set(CMAKE_BUILD_TYPE Debug)

if(SFML_OS_WINDOWS)
    set(SFML_GENERATE_PDB TRUE)
endif()

find_package(SFML 
    COMPONENTS graphics
    PATHS ${CMAKE_CURRENT_LIST_DIR}/sfml/build
    NO_CMAKE_SYSTEM_PATH)

add_executable(Galaga main.cpp)

target_link_libraries(Galaga
    sfml-graphics
    Galaga_lib)

add_custom_command(TARGET Galaga POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_LIST_DIR}/assets
    ${CMAKE_CURRENT_BINARY_DIR}/assets)
