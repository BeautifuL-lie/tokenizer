cmake_minimum_required(VERSION 3.12)

project(Tokenizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "src/*.cpp")

add_executable(tokenizer ${SOURCES})

target_include_directories(tokenizer PRIVATE include)

target_compile_options(tokenizer PRIVATE
    -Wall
    -Wextra
    -O2
)
