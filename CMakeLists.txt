cmake_minimum_required(VERSION 3.15)
project(TwoSumBootcamp)

# Language Standard: C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library logic
add_library(twosum_lib src/twosum.cpp)

# Production App
add_executable(twosum_app src/main.cpp)
target_link_libraries(twosum_app twosum_lib)

# Test runner
enable_testing()
add_executable(two_sum_tests tests/test_runner.cpp)
target_link_libraries(two_sum_tests twosum_lib)

# Fetch test data to build directory
configure_file(test_cases.txt test_cases.txt COPYONLY)

add_test(NAME AllTests COMMAND two_sum_tests)