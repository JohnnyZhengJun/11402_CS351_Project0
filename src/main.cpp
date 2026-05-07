#include <iostream>
#include <vector>

#include "twosum.h"

using namespace std;

int main() {
    vector<int> nums = {2, 7, 11, 15};

    auto result = twoSum_hash(nums, 9);

    if (!result.empty()) {
        cout << "Result: ["
             << result[0]
             << ", "
             << result[1]
             << "]\n";
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}