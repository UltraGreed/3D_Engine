cmake_minimum_required(VERSION 3.24)
project(3D_Engine)

set(CMAKE_CXX_STANDARD 23)

add_executable(3D_Engine_run main.cpp)

include_directories(3D_Engine_lib)
add_subdirectory(3D_Engine_lib)

target_link_libraries(3D_Engine_run 3D_Engine_lib)

add_subdirectory(Google_tests)
