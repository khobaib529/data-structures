cmake_minimum_required(VERSION 3.9)

project(ds)

# Build libarary
add_library(ds 
    "util/arena.cc"
)

target_include_directories(ds PUBLIC "include" ".")

# Build examples
add_subdirectory(examples)
