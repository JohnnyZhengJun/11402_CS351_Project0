# 1. Compile a lightweight, modular test runner
add_executable(RunSingleTest test_runner.cpp twosum.cpp)

# 2. Ingest the data file at CMake configure time
file(STRINGS "test_cases.txt" TEST_LINES)

# 3. Dynamically register each line as an isolated CTest entity
# Generate an isolated test for every single line
set(TEST_ID 1)
foreach(LINE IN LISTS TEST_LINES)
    if(NOT LINE STREQUAL "")
        # This passes the line arguments directly to your test_runner.cpp
        add_test(NAME "TwoSum_Case_${TEST_ID}" COMMAND two_sum_tests ${LINE})
        math(EXPR TEST_ID "${TEST_ID} + 1")
    endif()
endforeach()