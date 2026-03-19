# Two Sum Problem
## Description

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume each input has exactly one solution, and you cannot use the same element twice.

## Requirements
- **Language:** C++ 20 with STL `vector`

- **Implementations:**
    - `TwoSumArray`: Brute force O(n²) approach using nested loops
    - `TwoSumHashTable`: Optimized O(n) approach using hash map for single pass lookup

- **Test Cases:**
    - Basic case: `[2,7,11,15]`, target `9` → `[0,1]`
    - Negative numbers: `[-1,-2,-3]`, target `-5` → `[0,2]`
    - Large numbers: `[1000000000, -1000000000]`, target `0` → `[0,1]`
    - Minimum array size: `[1,2]`, target `3` → `[0,1]`
    
### Example
**Input:** `nums = [2,7,11,15]`, `target = 9`  
**Output:** `[0,1]`  
**Explanation:** `nums[0] + nums[1] = 2 + 7 = 9`

### Constraints
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

## Detail about GitHub Actions


