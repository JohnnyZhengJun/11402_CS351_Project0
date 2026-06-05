# Two Sum Problem

## Description

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume each input has exactly one solution, and you cannot use the same element twice.

## Requirements

- Language: C++20 with STL `vector`
- Use two functions:
  - `TwoSumArray`: brute force O(n^2) approach using nested loops
  - `TwoSumHashTable`: optimized O(n) approach using a hash map for single-pass lookup
- Each function should return the pair of indices whose values sum to `target`

## Test Cases

### Simple Case
- `[2,7,11,15]`, target `9` → `[0,1]`

### Edge/Corner Case
- Negative numbers: `[-1,-2,-3]`, target `-5` → `[0,2]`
- Large numbers: `[1000000000, -1000000000]`, target `0` → `[0,1]`

### Single Case
- Minimum array size: `[1,2]`, target `3` → `[0,1]`

### Stress Cases
- Large array with many elements
- Extreme values at boundaries

## Example

**Input:** `nums = [2,7,11,15]`, `target = 9`

**Output:** `[0,1]`

**Explanation:** `nums[0] + nums[1] = 2 + 7 = 9`

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

## Detail about GitHub Actions


