# 04: Master Test Plan

## 1. Testing Strategy Overview
The testing strategy for the Two Sum Bootcamp relies on **Data-Driven Automated Testing**. Rather than writing individual unit test functions for every possible scenario, a single test runner (`two_sum_tests`) dynamically ingests external data (`test_cases.txt`) and asserts correctness. This guarantees high test coverage, scalability, and absolute parity between the $O(n^2)$ and $O(n)$ algorithmic implementations.

## 2. Test Data Taxonomy
The `test_cases.txt` dataset is partitioned into four strict operational categories to stress different aspects of the algorithms:

* **Simple Cases:** Standard positive integer arrays with typical target sums. Verifies basic algorithmic correctness and array traversal.
* **Edge Cases:** Arrays containing negative integers, zeros, and duplicate values. Verifies that index pointers do not cross and that zero-sum calculations resolve correctly.
* **Single Amount (Constraint) Cases:** Arrays with fewer than the minimum required elements ($N < 2$), or test vectors explicitly designed to fail (no valid target exists). Verifies graceful error handling and empty vector returns.
* **Stress Cases:** Massive datasets containing up to 1,000 integers. Specifically engineered to benchmark the $O(n^2)$ array search against the $O(n)$ hash table search, verifying that neither algorithm causes memory faults or CI pipeline timeouts under load.

## 3. Test Environments
To prevent "works on my machine" failures, testing must be successfully executed across three progressively restrictive environments:

1. **Local Environment (Development):**
   * **OS:** macOS (Apple Silicon / ARM64)
   * **Compiler:** Apple Clang
   * **Purpose:** Rapid iterative development and syntax checking.
2. **Containerized Environment (Staging):**
   * **OS:** Ubuntu 22.04 LTS via Docker
   * **Compiler:** GCC (`g++`)
   * **Purpose:** Ensures the build system (CMake/Ninja) and C++ source code compile cleanly on a strict Linux architecture without relying on local host dependencies.
3. **Cloud Environment (Production/CI):**
   * **OS:** `ubuntu-latest` via GitHub Actions
   * **Compiler:** GCC (`g++`)
   * **Purpose:** The final gatekeeper. Completely clean, automated execution triggered by git pushes to mathematically guarantee the integrity of the repository.

## 4. Execution Protocol
All tests, regardless of environment, are invoked via the CMake testing driver (`ctest`). The execution sequence is standardized as follows:

```bash
# 1. Build generation
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=20

# 2. Compilation
cmake --build build

# 3. Automated Execution
ctest --test-dir build --output-on-failure