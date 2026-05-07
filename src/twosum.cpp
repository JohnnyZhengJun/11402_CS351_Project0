#include <vector>
#include <unordered_map>

using namespace std;

// O(n^2)
vector<int> twoSum_array(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

// O(n)
vector<int> twoSum_hash(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end())
            return {numMap[complement], i};

        numMap[nums[i]] = i;
    }

    return {};
}