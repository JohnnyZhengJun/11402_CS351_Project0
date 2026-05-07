cmake_minimum_required(VERSION 3.10)
project(TwoSumBootcamp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Core Executable
add_executable(twosum src/twosum.cpp)

# Testing Executable (Commented out until Step 2)
enable_testing()
add_executable(test_runner tests/test_twosum.cpp)
add_test(NAME TwoSumTests COMMAND test_runner)