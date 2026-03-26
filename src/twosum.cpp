#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // Method 1: Brute Force Array Approach
    vector<int> twoSum_array(vector<int>& nums, int target) {
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

    // Method 2: Optimized Hash Table Approach
    vector<int> twoSum_hash(vector<int>& nums, int target) 
    {
        unordered_map<int, int> numMap; 
        for (int i = 0; i < nums.size(); i++) 
        {
            int complement = target - nums[i];
            
            if (numMap.find(complement) != numMap.end())
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

// Helper function to print the results nicely
void printResult(const string& method, const vector<int>& result) {
    cout << method << " Result: ";
    if (result.empty()) {
        cout << "No solution found.\n";
    } else {
        cout << "[" << result[0] << ", " << result[1] << "]\n";
    }
}

int main() {
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Test Case 1: nums = [2, 7, 11, 15], target = 9\n";
    printResult("Array", solver.twoSum_array(nums1, target1));
    printResult("Hash ", solver.twoSum_hash(nums1, target1));
    cout << "-----------------------------------\n";

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Test Case 2: nums = [3, 2, 4], target = 6\n";
    printResult("Array", solver.twoSum_array(nums2, target2));
    printResult("Hash ", solver.twoSum_hash(nums2, target2));
    cout << "-----------------------------------\n";

    // Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Test Case 3: nums = [3, 3], target = 6\n";
    printResult("Array", solver.twoSum_array(nums3, target3));
    printResult("Hash ", solver.twoSum_hash(nums3, target3));

    return 0;
}