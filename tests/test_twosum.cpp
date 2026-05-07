#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of your pure function from src/twosum.cpp
vector<int> twoSum(const vector<int>& nums, int target);

// Modular test evaluator
void run_test(const string& test_name, const vector<int>& nums, int target, const vector<int>& expected) {
    vector<int> result = twoSum(nums, target);
    if (result == expected) {
        cout << "[PASS] " << test_name << "\n";
    } else {
        cout << "[FAIL] " << test_name << "\n";
    }
}

int main() {
    cout << "--- Running Two Sum Corner Case Tests ---\n";
    
    run_test("Negative Integers", {-1, -2, -3, -4}, -5, {1, 2});
    run_test("Duplicates", {3, 3}, 6, {0, 1});
    run_test("Zeroes", {0, 4, 3, 0}, 0, {0, 3});
    run_test("No Solution", {1, 2, 3}, 10, {});
    run_test("Minimum Constraint", {5}, 5, {});
    
    return 0;
}