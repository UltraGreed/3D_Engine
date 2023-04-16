project(Google_tests)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_tests_run math_test.cpp)

target_link_libraries(Google_tests_run 3D_Engine_lib)

target_link_libraries(Google_tests_run gtest gtest_main)
