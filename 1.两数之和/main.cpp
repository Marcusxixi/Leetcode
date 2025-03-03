#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public: vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashMap.find(target - nums[i]);
            // find 找到了匹配的元素，在哈希表中存在这个元素满足 target - nums[i] == nums[i]
            if (it != hashMap.end()) {
                return {it->second, i};
            }
            hashMap[nums[i]] = i;
            

        }
        return {};

    }

};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    for (int num : result) {
        cout << num << endl;
    }
}
