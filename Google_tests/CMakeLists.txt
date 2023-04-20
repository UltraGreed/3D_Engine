# Add an executable target for the Google tests
add_executable(Google_Tests
        matrix_tests.cpp
        # Add any other Google tests source files here
        vector_tests.cpp point_tests.cpp coordinate_system_tests.cpp vector_space_tests.cpp)

# Link the Math and CoordinateSystem libraries to the Google_Tests executable
target_link_libraries(Google_Tests
        Math
        CoordinateSystem
        )
# Link the gtests libraries
target_link_libraries(Google_Tests
        gtest
        gtest_main
        )

# Include the Math and CoordinateSystem header files
target_include_directories(Google_Tests
        PRIVATE
        ../3D_Engine_lib/Math
        ../3D_Engine_lib/CoordinateSystem
        )

add_subdirectory(lib)

# Include the Google Test headers
include_directories(Google_Tests
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        )

# Set the output directory for the Google Test executable
set_target_properties(Google_Tests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
        )