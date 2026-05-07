# 05: Acceptance Tests

## 1. Introduction
This document outlines the formal User Acceptance Testing (UAT) procedures for the Two Sum Bootcamp. These tests are designed to be executed by a human evaluator (e.g., the grading professor) to verify that the software satisfies all functional and non-functional requirements specified in the SRS.

## 2. Prerequisites
Before initiating acceptance testing, the evaluator must ensure the following environment conditions are met:
* macOS or Linux host operating system.
* CMake (v3.15+) and Ninja installed.
* Docker Desktop installed and running.
* The repository is cloned locally and the terminal is navigated to the project root directory.

---

## 3. Test Cases

### Test Case 1: Native Compilation (macOS/Linux)
* **Objective:** Verify the C++20 code compiles cleanly on the host OS using the CMake build system.
* **Traceability:** NFR-1.1, NFR-1.2, NFR-3.1
* **Execution:**
  1. Run: `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=20`
  2. Run: `cmake --build build`
* **Expected Result:** The build system generates two executables (`twosum_app` and `two_sum_tests`) in the `build/` directory without any compiler warnings or linker errors.

### Test Case 2: Interactive CLI Application
* **Objective:** Verify the user-facing application handles inputs correctly and calculates the Two Sum indices via the Hash Table approach.
* **Traceability:** FR-1.1, FR-1.2, FR-1.3, FR-1.4
* **Execution:**
  1. Run: `./build/twosum_app`
  2. Input elements: `4`
  3. Input array: `2 7 11 15`
  4. Input target: `9`
* **Expected Result:** The console strictly outputs: `Success! Solution found at indices: [0, 1]`.

### Test Case 3: Automated Data-Driven Validation
* **Objective:** Verify the test runner accurately parses the 4,000+ line `test_cases.txt` file and validates the $O(n^2)$ array algorithm against the $O(n)$ hash algorithm.
* **Traceability:** FR-2.1, FR-2.2, FR-3.1, FR-3.2, FR-3.3, NFR-2.1
* **Execution:**
  1. Run: `./build/two_sum_tests`
* **Expected Result:** The program executes in under 2 seconds and outputs: `Processed [X] unique scenarios. ALL TESTS PASSED.` Exit code must be `0`.

### Test Case 4: Containerized Execution (Docker)
* **Objective:** Verify the system compiles and passes all automated tests inside a pristine, isolated Ubuntu environment.
* **Traceability:** NFR-3.2, NFR-3.3
* **Execution:**
  1. Run: `docker build -t twosum-bootcamp .`
  2. Run: `docker run --rm twosum-bootcamp`
* **Expected Result:** Docker successfully pulls the Ubuntu image, builds the project, executes CTest, and outputs `100% tests passed, 0 tests failed out of 1`.

### Test Case 5: Continuous Integration (GitHub Actions)
* **Objective:** Verify the cloud infrastructure automates the testing protocol upon repository pushes.
* **Traceability:** NFR-4.1, NFR-4.2
* **Execution:**
  1. Navigate to the GitHub repository web interface.
  2. Open the **Actions** tab.
  3. Inspect the most recent workflow run for the `ci.yml` pipeline.
* **Expected Result:** All workflow steps (Install Dependencies, Configure, Build, Test) exhibit a green passing status indicator.