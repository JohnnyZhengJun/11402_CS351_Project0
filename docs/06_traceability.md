# 06: Requirements Traceability Matrix (RTM)

## 1. Purpose
The Requirements Traceability Matrix maps the functional and non-functional requirements specified in the SRS (`02_SRS.md`) to the implemented software components (`03_SDS.md`) and their corresponding validation protocols (`05_acceptance_tests.md`). This ensures complete test coverage and prevents scope creep.

## 2. Traceability Matrix

| Req ID  | Requirement Description | Implemented Component | Validation Test (UAT) | Status |
| :--- | :--- | :--- | :--- | :--- |
| **FR-1.1** | Interactive CLI executable | `src/main.cpp` | Test Case 2 | Implemented |
| **FR-1.2** | Accept array elements & target | `src/main.cpp` | Test Case 2 | Implemented |
| **FR-1.3** | Reject invalid sizes ($N < 2$) | `src/main.cpp` | Test Case 2 | Implemented |
| **FR-1.4** | Output 0-based indices or error | `src/main.cpp` | Test Case 2 | Implemented |
| **FR-2.1** | Array implementation $O(n^2)$ | `src/twosum.cpp` (`TwoSumArray`) | Test Case 3 | Implemented |
| **FR-2.2** | Hash Table implementation $O(n)$ | `src/twosum.cpp` (`TwoSumHashTable`) | Test Case 3 | Implemented |
| **FR-2.3** | Identical vector signatures | `src/twosum.h` | Test Case 1 | Implemented |
| **FR-3.1** | Secondary test executable | `tests/test_runner.cpp` | Test Case 3 | Implemented |
| **FR-3.2** | Parse `test_cases.txt` autonomously | `tests/test_runner.cpp` | Test Case 3 | Implemented |
| **FR-3.3** | Assert algorithmic parity | `tests/test_runner.cpp` | Test Case 3 | Implemented |
| **FR-3.4** | Fail-fast termination | `tests/test_runner.cpp` | Test Case 3 | Implemented |
| **NFR-1.1**| C++20 Standard strict adherence | `CMakeLists.txt` | Test Case 1, 4 | Verified |
| **NFR-1.2**| CMake & Ninja build system | `CMakeLists.txt` | Test Case 1, 4 | Verified |
| **NFR-2.1**| Performant scaling (1000-elements) | `src/twosum.cpp