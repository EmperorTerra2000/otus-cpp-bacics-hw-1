cmake_minimum_required(VERSION 3.15)

project(03.homework)

add_executable(main 
    main.cpp
    main.h
    guessTheNumber.h
    guessTheNumber.cpp
)

set_target_properties(main PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
  CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    target_compile_options(main PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

    target_compile_options(main PRIVATE /EHsc /W4 /WX)

endif()
