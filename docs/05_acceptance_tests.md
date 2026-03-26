# Acceptance Tests

## TwoSum Problem

### Test Case 1: Valid Pair Found
**Given:** Array `[2, 7, 11, 15]` and target `9`  
**When:** Finding two numbers that sum to target  
**Then:** Return indices `[0, 1]` (representing values 2 and 7)

### Test Case 2: Multiple Valid Pairs
**Given:** Array `[3, 3]` and target `6`  
**When:** Finding two numbers that sum to target  
**Then:** Return indices `[0, 1]`

### Test Case 3: No Valid Pair
**Given:** Array `[1, 2, 3]` and target `10`  
**When:** Finding two numbers that sum to target  
**Then:** Return empty array or null

### Test Case 4: Negative Numbers
**Given:** Array `[-1, -2, -3, 5, 6]` and target `4`  
**When:** Finding two numbers that sum to target  
**Then:** Return indices for `-1` and `5` (or `5` and `-1`)

### Test Case 5: Single Element
**Given:** Array `[5]` and target `10`  
**When:** Finding two numbers that sum to target  
**Then:** Return empty array (insufficient elements)
