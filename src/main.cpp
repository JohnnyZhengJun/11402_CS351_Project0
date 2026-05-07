#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum_hash(const vector<int>& nums, int target);

int main() {
    vector<int> nums = {2, 7, 11, 15};

    auto res = twoSum_hash(nums, 9);

    if (!res.empty()) {
        cout << "Hash Success: ["
             << res[0] << "," << res[1] << "]\n";
    }

    return 0;
}