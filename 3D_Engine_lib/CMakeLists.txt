cmake_minimum_required(VERSION 3.23)

project(3D_Engine)

set(CMAKE_CXX_STANDARD 23)

set(HEADER_FILES Camera.h Objects.h MatrixBased.h CoordinateSystem.h)

set(SOURCE_FILES Camera.cpp Objects.cpp Matrix.cpp BaseMatrix.cpp Vector.cpp Point.cpp VectorSpace.cpp CoordinateSystem.cpp)

add_library(3D_Engine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
