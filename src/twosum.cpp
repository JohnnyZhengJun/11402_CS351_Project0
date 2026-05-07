#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Method 1: Brute Force Array Approach - O(n^2)
vector<int> twoSum_array(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// Method 2: Optimized Hash Table Approach - O(n)
vector<int> twoSum_hash(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap; 
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    cout << "Testing Brute Force... ";
    auto res1 = twoSum_array(nums, target);
    if(!res1.empty()) cout << "[" << res1[0] << "," << res1[1] << "]\n";

    cout << "Testing Hash Table... ";
    auto res2 = twoSum_hash(nums, target);
    if(!res2.empty()) cout << "[" << res2[0] << "," << res2[1] << "]\n";
    
    return 0;
}