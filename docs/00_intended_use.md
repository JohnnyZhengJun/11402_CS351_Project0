# 00: Intended Use Statement

## 1. Product Description

The **Two Sum Bootcamp** is a dual-mode C++20 software suite designed to solve the classic "Two Sum" algorithmic problem. It provides both an interactive Command Line Interface (CLI) for human users and a robust, data-driven testing executable for automated benchmarking. The system explicitly implements two distinct algorithms to validate correctness and evaluate computational complexity:

* **Array-Based Approach:** $O(n^2)$ time complexity using brute-force iteration.
* **Hash-Table Approach:** $O(n)$ time complexity using `std::unordered_map`.

## 2. Target Audience

* **Academic Evaluators:** To review compliance with rigorous C++20 standards, algorithmic correctness, and CI/CD best practices.
* **Software Engineers:** To utilize as a foundational reference for bootstrapping C++ projects with CMake, Ninja, and Docker integration.
* **Automated Systems (CI/CD):** Designed to be executed headlessly by GitHub Actions for continuous integration and regression testing.

## 3. Operational Environment

The software is architected to be platform-agnostic but is strictly validated against the following environments:

* **Local Development:** macOS (Apple Silicon / ARM64) compiled via Clang/GCC.
* **Containerized Sandbox:** Ubuntu 22.04 LTS (Docker) ensuring zero dependency leakage.
* **Continuous Integration:** GitHub Actions (`ubuntu-latest` runner).

## 4. Intended Operations

1. **Interactive Mode (`twosum_app`):** Accepts standard input (`std::cin`) from a user to dynamically define an array size, populate elements, and query a target sum. It defaults to the optimized Hash Table approach for $O(1)$ lookup performance.
2. **Benchmarking Mode (`two_sum_tests`):** Parses massive external datasets (e.g., thousands of numerical vectors) via `std::ifstream`, bypassing standard input to execute a rigorous suite of simple, edge, constraint, and stress cases. It strictly enforces that both internal algorithms yield identical indices.

## 5. Out of Scope

* Handling floating-point arrays or non-integer inputs.
* Handling arrays where zero or multiple distinct solutions exist (the specification assumes exactly one valid solution per dataset).
* Graphical User Interface (GUI) implementations.
