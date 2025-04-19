#include<vector>
using namespace std;
#include<unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash_set;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > k) {
                hash_set.erase(nums[i - k - 1]);
            }
            if (hash_set.count(nums[i])) return true;
            hash_set.emplace(nums[i]);
        }
        return false;
    }
};