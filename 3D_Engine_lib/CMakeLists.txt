cmake_minimum_required(VERSION 3.24)

project(3D_Engine)

set(CMAKE_CXX_STANDARD 23)

set(HEADER_FILES Camera.h Math/MatrixBased.h CoordinateSystem/CoordinateSystem.h)

set(SOURCE_FILES Camera.cpp Math/Matrix.cpp Math/BaseMatrix.cpp Math/Vector.cpp CoordinateSystem/Point.cpp CoordinateSystem/VectorSpace.cpp CoordinateSystem/CoordinateSystem.cpp)

add_library(3D_Engine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(3D_Engine_lib PRIVATE Math CoordinateSystem)

add_executable(3D_Engine main.cpp)