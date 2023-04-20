cmake_minimum_required(VERSION 3.20)

# Set the project name and version
project(3D_Engine VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the Math and CoordinateSystem libraries
add_subdirectory(3D_Engine_lib)

# Include the Google tests executable
add_subdirectory(Google_tests)