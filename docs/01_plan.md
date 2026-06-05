# 01: Project Execution Plan

## 1. Project Objective

To engineer, test, and deploy a C++20 software suite that solves the "Two Sum" algorithmic challenge. The project will demonstrate progressive software engineering practices, evolving from a local, interactive CLI application to a containerized, data-driven system validated by Continuous Integration (CI).

## 2. Work Breakdown Structure (WBS)

### Phase 1: Core Algorithmic Implementation

* **Milestone:** Functional C++ logic yielding correct indices for predefined arrays.

* **Tasks:**
  * Define the header specifications (`twosum.h`).
  * Implement the brute-force Array search ($O(n^2)$ time complexity).
  * Implement the optimized Hash Table search ($O(n)$ time complexity).
  * Build the interactive CLI application (`main.cpp`) for manual user verification.

### Phase 2: Data-Driven Test Engineering

* **Milestone:** Automated validation against 4,000 distinct mathematical scenarios.

* **Tasks:**
  * Generate a massive, structured dataset (`test_cases.txt`) covering Simple, Edge, Single, and Stress cases.
  * Develop a robust C++ test runner (`test_runner.cpp`) capable of safely parsing the data file and executing both algorithms simultaneously.
  * Implement fail-fast validation logic to ensure the $O(n^2)$ and $O(n)$ outputs perfectly match.

### Phase 3: Infrastructure & Containerization

* **Milestone:** Reproducible build environment independent of the host operating system.

* **Tasks:**
  * Configure `CMakeLists.txt` to enforce C++20 standards, link libraries, and register CTest configurations.
  * Write a `Dockerfile` targeting `ubuntu:22.04`.
  * Install necessary build tools (`g++`, `cmake`, `ninja-build`) within the container.
  * Configure a `.dockerignore` file to prevent host-system build artifacts from corrupting the containerized build.

### Phase 4: Continuous Integration Deployment

* **Milestone:** Automated cloud validation upon every repository push.

* **Tasks:**
  * Draft the GitHub Actions workflow (`.github/workflows/ci.yml`).
  * Configure the `ubuntu-latest` runner to execute the CMake build and test sequence.
  * Verify 100% test passage in the cloud environment.

## 3. Key Deliverables

1. `src/twosum.cpp` & `src/twosum.h` (Core Logic)
2. `src/main.cpp` (Interactive CLI)
3. `tests/test_runner.cpp` & `test_cases.txt` (Validation Suite)
4. `CMakeLists.txt` (Build System Specification)
5. `Dockerfile` (Container Specification)
6. `.github/workflows/ci.yml` (CI Pipeline Specification)

## 4. Risk Management

* **Risk:** Cross-platform compilation errors (e.g., developing on macOS ARM64 but deploying to Ubuntu x86_64).
  * **Mitigation:** Strict utilization of Docker to simulate the Ubuntu deployment environment locally before pushing to GitHub.

* **Risk:** CI pipeline timeouts due to massive nested loops in the $O(n^2)$ algorithm during the 1,000-element Stress tests.
  * **Mitigation:** Ensure `-DCMAKE_BUILD_TYPE=Release` is utilized in all build steps to enforce `-O3` compiler optimizations.
