#pragma once
#include <vector>

/**
 * Requirement: Provide two solution implementations.
 * Language: C++20 with STL vector.
 */

// Direct array-based approach - O(n^2)
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target);

// Hash-table-based approach - O(n)
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target);