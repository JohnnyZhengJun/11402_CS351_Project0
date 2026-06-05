# 1. Compile a lightweight, modular test runner
add_executable(RunSingleTest test_runner.cpp twosum.cpp)

# 2. Ingest the data file at CMake configure time
file(STRINGS "test_cases.txt" TEST_LINES)

# 3. Dynamically register each line as an isolated CTest entity
set(TEST_ID 1)
foreach(LINE IN LISTS TEST_LINES)
    # Skip empty lines to prevent malformed commands
    if(NOT LINE STREQUAL "")
        # The unquoted ${LINE} variable expands into individual argv arguments
        add_test(NAME "TwoSum_Test_${TEST_ID}" COMMAND RunSingleTest ${LINE})
        math(EXPR TEST_ID "${TEST_ID} + 1")
    endif()
endforeach()