#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int ret = nums.size() + 1;
        int count = 0;
        for (int right = 0; right < nums.size() - 1; ++right) {
            count += nums[right];
            while (count >= target) {
                ret = min(ret, right - left + 1);
                count -= nums[left];
                ++left;
            }
        }
        return ret <= nums.size() ? ret : 0;
    }
};