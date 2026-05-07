#include <iostream>
#include <vector>
#include "twosum.h"

using namespace std;

int main() {
    int n, target, val;
    vector<int> nums;

    cout << "--- Two Sum Interactive CLI ---\n";
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 2) {
        cerr << "Error: Array must have at least 2 elements.\n";
        return 1;
    }

    cout << "Enter " << n << " integers (space separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    cout << "Enter target sum: ";
    cin >> target;

    // We use the optimized Hash approach for the production CLI
    auto result = TwoSumHashTable(nums, target);

    if (!result.empty()) {
        cout << "Success! Solution found at indices: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}