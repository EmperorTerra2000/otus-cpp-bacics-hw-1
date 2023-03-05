cmake_minimum_required(VERSION 3.5)

project(containers)

add_executable(containers
    src/main.cpp
)

target_include_directories(containers PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(containers PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(containers PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(containers PUBLIC cxx_std_17)