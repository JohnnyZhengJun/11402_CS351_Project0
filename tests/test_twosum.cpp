#include <iostream>
#include <vector>
#include <string>

#include "../src/twosum.h"

using namespace std;

bool is_valid_result(
    const vector<int>& nums,
    int target,
    const vector<int>& result
) {
    // No solution expected
    if (result.empty()) {
        return false;
    }

    // Must contain exactly two indices
    if (result.size() != 2) {
        return false;
    }

    int i = result[0];
    int j = result[1];

    // Index bounds check
    if (i < 0 || j < 0 ||
        i >= nums.size() ||
        j >= nums.size() ||
        i == j) {
        return false;
    }

    return nums[i] + nums[j] == target;
}

void run_test(
    const string& name,
    const vector<int>& nums,
    int target,
    bool expect_solution
) {
    auto res_arr = twoSum_array(nums, target);
    auto res_hash = twoSum_hash(nums, target);

    bool arr_ok = expect_solution
        ? is_valid_result(nums, target, res_arr)
        : res_arr.empty();

    bool hash_ok = expect_solution
        ? is_valid_result(nums, target, res_hash)
        : res_hash.empty();

    if (arr_ok && hash_ok) {
        cout << "[PASS] " << name << "\n";
    } else {
        cout << "[FAIL] " << name << "\n";

        cout << "Array Result: ";
        for (int x : res_arr) cout << x << " ";
        cout << "\n";

        cout << "Hash Result: ";
        for (int x : res_hash) cout << x << " ";
        cout << "\n";

        exit(1);
    }
}
int main() {
    cout << "--- Running Two Sum Tests ---\n";

    // 1. SIMPLE CASES
    run_test("Standard", {2, 7, 11, 15}, 9, true);
    run_test("Large Gap", {1, 100}, 101, true);

    // 2. EDGE CASES
    run_test("Negative Numbers", {-1, -2, -3, -4}, -5, true);
    run_test("Duplicates", {3, 3}, 6, true);
    run_test("Zero Sum", {0, 5, -5, 0}, 0, true);
    run_test("No Solution", {1, 2, 3}, 10, false);

    // 3. SINGLE AMOUNT / CONSTRAINTS
    run_test("Single Element", {5}, 5, false);
    run_test("Empty Array", {}, 0, false);

    // 4. STRESS TEST
    // Generates 10,000 elements: [0, 1, 2, ... 9999]
    // Target: 19997 (Last two elements: 9998 + 9999)
    vector<int> stress_nums;
    for (int i = 0; i < 10000; ++i) stress_nums.push_back(i);
    run_test("Stress Test (N=10,000)", stress_nums, 19997, true);

    cout << "\nAll tests passed successfully.\n";
    return 0;
}