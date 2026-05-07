#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Standalone O(n^2) implementation
vector<int> twoSum_array(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) return {i, j};
        }
    }
    return {};
}

// Standalone O(n) implementation
vector<int> twoSum_hash(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap; 
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) return {numMap[complement], i};
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    // Basic verification for local runs
    vector<int> nums = {2, 7, 11, 15};
    auto res = twoSum_hash(nums, 9);
    if (!res.empty()) cout << "Hash Success: [" << res[0] << "," << res[1] << "]\n";
    return 0;
}