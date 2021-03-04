cmake_minimum_required(VERSION 3.0)
project(softwarerender)

include_directories(vendor/minifb/include)

add_subdirectory(vendor/minifb)

add_executable(renderer src/main.cc)
target_link_libraries(renderer minifb)