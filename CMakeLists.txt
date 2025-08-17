cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(MEMORY_ALLOCATOR VERSION 1.0)
set(MEMORY_ALLOCATOR 1.0)

set(CMAKE_CXX_STANDARD_REQUIRED ON)




add_executable(MEMORY_ALLOCATOR src/main.cpp)




target_include_directories(MEMORY_ALLOCATOR
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

