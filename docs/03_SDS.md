# 03: Software Design Specification (SDS)

## 1. Architectural Overview
The Two Sum Bootcamp suite employs a modular, statically-linked architecture. The core algorithmic logic is isolated within a shared library (`twosum_lib`), enabling multiple front-end executables to consume the exact same mathematical functions without code duplication.

The system is partitioned into three primary components:
1. **Core Library (`src/twosum.cpp`, `src/twosum.h`):** Contains the stateless, pure functions responsible for integer array processing.
2. **Interactive CLI (`src/main.cpp`):** Handles user input/output streams (`std::cin`, `std::cout`) and executes the optimized Hash Table algorithm for real-time responsiveness.
3. **Automated Test Runner (`tests/test_runner.cpp`):** An autonomous execution engine that parses file I/O streams (`std::ifstream`), executes both algorithms concurrently, and validates output parity.

## 2. Directory Structure
```text
11402_CS351_Project0/
├── CMakeLists.txt        # Build system configuration
├── Dockerfile            # Containerization manifest
├── test_cases.txt        # Data-driven validation dataset
├── src/
│   ├── main.cpp          # Interactive application entry point
│   ├── twosum.h          # Public API declarations
│   └── twosum.cpp        # Algorithmic implementations
├── tests/
│   └── test_runner.cpp   # Automated validation engine
└── .github/
    └── workflows/
        └── ci.yml        # Cloud deployment pipeline