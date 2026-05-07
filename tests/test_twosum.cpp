#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Match the source file's names exactly
vector<int> twoSum_array(const vector<int>& nums, int target);
vector<int> twoSum_hash(const vector<int>& nums, int target);

void run_test(const string& name, const vector<int>& nums, int target, const vector<int>& expected) {
    auto res_arr = twoSum_array(nums, target);
    auto res_hash = twoSum_hash(nums, target);

    if (res_arr == expected && res_hash == expected) {
        cout << "[PASS] " << name << "\n";
    } else {
        cout << "[FAIL] " << name << " (Check algorithm implementations)\n";
        exit(1); // Exit with error code to trigger CI failure if a test fails
    }
}

int main() {
    cout << "--- Running Dual-Algorithm Corner Case Tests ---\n";
    
    run_test("Standard", {2, 7, 11, 15}, 9, {0, 1});
    run_test("Negative", {-1, -2, -3, -4}, -5, {1, 2});
    run_test("Duplicates", {3, 3}, 6, {0, 1});
    run_test("No Solution", {1, 2, 3}, 10, {});
    
    return 0;
}