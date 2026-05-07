cmake_minimum_required(VERSION 3.10)
project(TwoSumBootcamp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Main executable
add_executable(twosum
    src/main.cpp
    src/twosum.cpp
)

# Testing
enable_testing()

add_executable(test_runner
    tests/test_twosum.cpp
    src/twosum.cpp
)

add_test(NAME TwoSumTests COMMAND test_runner)