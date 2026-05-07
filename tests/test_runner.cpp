#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../src/twosum.h"

using namespace std;

// Validates if the returned indices are correct
bool is_valid(const vector<int>& nums, int target, const vector<int>& res) {
    if (res.empty()) return false;
    if (res.size() != 2 || res[0] == res[1]) return false;
    return nums[res[0]] + nums[res[1]] == target;
}

int main() {
    ifstream file("tst.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open tst.txt. Ensure it is in the build directory.\n";
        return 1;
    }

    string category;
    int target, expect_val, n, temp;
    int pass_count = 0, total_count = 0;

    cout << "--- Executing Data-Driven Pipeline (tst.txt) ---\n";

    while (file >> category >> target >> expect_val >> n) {
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            if (file >> temp) nums.push_back(temp);
        }

        bool expect_sol = (expect_val == 1);
        auto r1 = twoSum_array(nums, target);
        auto r2 = twoSum_hash(nums, target);

        bool ok1 = expect_sol ? is_valid(nums, target, r1) : r1.empty();
        bool ok2 = expect_sol ? is_valid(nums, target, r2) : r2.empty();

        if (ok1 && ok2) {
            pass_count++;
        } else {
            cerr << "[FAIL] " << category << " case failed at index " << total_count << "\n";
            return 1; 
        }
        total_count++;
    }

    cout << "Successfully processed " << total_count << " test cases.\n";
    cout << "Final Result: " << pass_count << "/" << total_count << " Passed.\n";

    return 0;
}