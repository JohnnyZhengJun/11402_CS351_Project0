#include "twosum.h"
#include <unordered_map>

using namespace std;

vector<int> twoSum_array(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) return {i, j};
        }
    }
    return {};
}

vector<int> twoSum_hash(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) return {numMap[complement], i};
        numMap[nums[i]] = i;
    }
    return {};
}