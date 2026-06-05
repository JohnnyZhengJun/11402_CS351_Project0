#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "../twosum.h"

int main(int argc, char* argv[]) {
    // Enforce strict arity bounds based on the data schema
    if (argc < 5) {
        std::cerr << "FAIL: Insufficient test parameters provided.\n";
        return 1;
    }

    std::string category   = argv[1];
    int target             = std::stoi(argv[2]);
    bool expected_exists   = std::stoi(argv[3]);
    int n                  = std::stoi(argv[4]);

    if (argc != 5 + n) {
        std::cerr << "FAIL: Mismatch between array length N and provided elements.\n";
        return 1;
    }

    // Populate the test vector
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = std::stoi(argv[5 + i]);
    }

    // Execute core module
    auto result = TwoSumHashTable(nums, target);
    bool actual_exists = !result.empty();

    // Verification
    if (actual_exists != expected_exists) {
        std::cerr << "FAIL: Expected solution presence " << expected_exists 
                << ", but got " << actual_exists << ".\n";
        return 1; 
    }

    // If expected exists, verify the sum strictly equals the target
    if (expected_exists) {
        if (nums[result[0]] + nums[result[1]] != target) {
            std::cerr << "FAIL: Returned indices do not sum to target.\n";
            return 1;
        }
    }

    return 0; // CTest reads exit code 0 as PASSED
}