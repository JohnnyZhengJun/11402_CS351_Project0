# 02: Software Requirements Specification (SRS)

## 1. Introduction

This document defines the functional and non-functional requirements for the **Two Sum Bootcamp** software suite. It serves as the definitive contract for system capabilities, performance thresholds, and environmental constraints.

## 2. Functional Requirements (FR)

### FR-1: Interactive Command Line Interface (CLI)

* **FR-1.1:** The system shall provide an interactive executable (`twosum_app`) that prompts the user for standard input (`std::cin`).
* **FR-1.2:** The system shall accept an integer $N$ representing the array size, followed by $N$ integer elements, and finally an integer target sum.
* **FR-1.3:** The system shall reject invalid array sizes ($N < 2$) with an appropriate error message and a non-zero exit code.
* **FR-1.4:** The system shall output the correct 0-based indices if a solution exists, or a "No solution found" message if none exists.

### FR-2: Algorithmic Implementations

* **FR-2.1:** The system shall implement a brute-force function `TwoSumArray` with a strict $O(n^2)$ time complexity constraint.
* **FR-2.2:** The system shall implement an optimized function `TwoSumHashTable` using standard library hash maps with an expected $O(n)$ time complexity constraint.
* **FR-2.3:** Both functions must possess the exact same signature: returning a `std::vector<int>` containing the two valid indices or an empty vector upon failure.

### FR-3: Data-Driven Test Automation

* **FR-3.1:** The system shall provide a secondary executable (`two_sum_tests`) strictly for automated validation.
* **FR-3.2:** The test runner shall autonomously parse an external data file (`test_cases.txt`) formatted with category labels, expected outcomes, array sizes, and array data.
* **FR-3.3:** The test runner shall execute *both* algorithmic implementations on every parsed dataset and assert that both return mathematically valid, identical results.
* **FR-3.4:** The test runner shall employ a "fail-fast" architecture: encountering any mathematical failure or algorithm discrepancy must immediately terminate the program with exit code `1`.

## 3. Non-Functional Requirements (NFR)

### NFR-1: Standard and Compilation

* **NFR-1.1:** The codebase must strictly adhere to the **C++20** standard.
* **NFR-1.2:** The build system must utilize **CMake** (minimum version 3.15) and generate build files via **Ninja**.

### NFR-2: Performance

* **NFR-2.1:** The hash-table implementation must resolve the 1,000-element Stress cases without inducing pipeline timeouts.
* **NFR-2.2:** Release builds must utilize `-O3` compiler optimizations (configured via `CMAKE_BUILD_TYPE=Release`).

### NFR-3: Portability & Containerization

* **NFR-3.1:** The software must be compilable natively on macOS (Apple Silicon).
* **NFR-3.2:** The software must be fully containerized via Docker using `ubuntu:22.04` as the base image.
* **NFR-3.3:** The containerized build must execute completely isolated from the host OS (enforced via `.dockerignore`).

### NFR-4: Continuous Integration

* **NFR-4.1:** The software must integrate with GitHub Actions.
* **NFR-4.2:** Commits to the `main` branch or pull requests must trigger an automated build and test sequence via `ctest`.
