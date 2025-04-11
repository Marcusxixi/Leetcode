#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash_table.count(target - nums[i])) return {hash_table[target - nums[i]], i};
            hash_table[nums[i]] = i;
        }
        return {-1, -1};
    }
};