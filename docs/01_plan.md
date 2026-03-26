# TwoSum Algorithm Plan

## Overview
Plan for implementing a solution to find two numbers in an array that sum to a target value.

## Problem Statement
- **Input**: Array of integers and a target sum
- **Output**: Indices of two numbers that add up to the target
- **Constraint**: Each element can only be used once

## Approach Options

### 1. Brute Force
- Nested loops to check all pairs
- **Time**: O(n²)
- **Space**: O(1)

### 2. Hash Map (Recommended)
- Store visited numbers in a map
- For each number, check if `target - number` exists
- **Time**: O(n)
- **Space**: O(n)

### 3. Two Pointers (Sorted)
- Sort array first, then use two pointers
- **Time**: O(n log n)
- **Space**: O(1) or O(n) depending on sort

## Implementation Steps
1. Choose hash map approach for optimal performance
2. Create data structure to store value-index pairs
3. Iterate through array once
4. Return indices when pair found

## Edge Cases
- Negative numbers
- Duplicate values
- No valid pair exists
- Array with fewer than 2 elements
