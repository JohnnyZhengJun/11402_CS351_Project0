# 1. CMake Boilerplate (Resolves warnings)
cmake_minimum_required(VERSION 3.20)
project(TwoSumProject)

# 2. Core Application Executable
add_executable(TwoSumApp src/main.cpp src/twosum.cpp)

# 3. Isolated Test Runner Executable
# Explicitly targets the files inside their respective directories
add_executable(two_sum_tests tests/test_runner.cpp src/twosum.cpp)

# 4. Dynamic Test Parser
file(STRINGS "test_cases.txt" TEST_LINES)
set(TEST_ID 1)
foreach(LINE IN LISTS TEST_LINES)
    if(NOT LINE STREQUAL "")
        add_test(NAME "TwoSum_Case_${TEST_ID}" COMMAND two_sum_tests ${LINE})
        math(EXPR TEST_ID "${TEST_ID} + 1")
    endif()
endforeach()