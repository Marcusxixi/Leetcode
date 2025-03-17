#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public: vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash_table.find(target - nums[i]);
            if (it != hash_table.end()) {
                return {it->second, i};
            } else {
                hash_table[nums[i]] = i;
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    Solution sol;
    cout << sol.twoSum(nums, 9)[0] << " " << sol.twoSum(nums, 9)[1] << endl;
}