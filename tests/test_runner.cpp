#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "../src/twosum.h"

using namespace std;

// Helper: Validates index safety and mathematical correctness
bool is_valid(const vector<int>& nums, int target, const vector<int>& res) {
    if (res.empty()) return false;
    if (res.size() != 2 || res[0] == res[1]) return false;
    if (res[0] >= (int)nums.size() || res[1] >= (int)nums.size()) return false;
    return nums[res[0]] + nums[res[1]] == target;
}

int main() {
    ifstream file("test_cases.txt");
    if (!file.is_open()) {
        cerr << "CRITICAL ERROR: test_cases.txt not found.\n";
        return 1;
    }

    string category;
    int target, expect_success, n, val;
    int total = 0, passed = 0;

    cout << "--- Starting Data-Driven Two Sum Test Suite ---\n";

    while (file >> category) {
        // Handle comment lines
        if (category[0] == '#') {
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (!(file >> target >> expect_success >> n)) break;

        vector<int> nums;
        nums.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (file >> val) nums.push_back(val);
        }

        auto res_arr = TwoSumArray(nums, target);
        auto res_hash = TwoSumHashTable(nums, target);

        bool expect_solution = (expect_success == 1);
        bool arr_ok = expect_solution ? is_valid(nums, target, res_arr) : res_arr.empty();
        bool hash_ok = expect_solution ? is_valid(nums, target, res_hash) : res_hash.empty();

        if (arr_ok && hash_ok) {
            passed++;
        } else {
            cerr << "[FAIL] Category: " << category << " | Case #" << total + 1 << "\n";
            return 1; // Strict fail-fast discipline
        }
        total++;
    }

    cout << "Processed " << total << " unique scenarios. ALL TESTS PASSED.\n";
    return 0;
}