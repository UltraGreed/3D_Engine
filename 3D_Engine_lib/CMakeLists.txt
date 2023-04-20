# Add a library target for the Math classes
add_library(Math
        Math/Matrix.tpp
        Math/BaseMatrix.tpp
        Math/Vector.tpp
        )

target_include_directories(Math PUBLIC Math)

# Add a library target for the CoordinateSystem classes
add_library(CoordinateSystem
        CoordinateSystem/Point.tpp
        CoordinateSystem/VectorSpace.tpp
        CoordinateSystem/CoordinateSystem.tpp
        )

target_include_directories(CoordinateSystem PUBLIC CoordinateSystem)

# Set linker language
set_target_properties(Math CoordinateSystem
        PROPERTIES
        LINKER_LANGUAGE CXX
        )
