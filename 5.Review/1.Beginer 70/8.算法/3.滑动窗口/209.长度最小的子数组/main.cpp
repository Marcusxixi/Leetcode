#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, left = 0, ret = n + 1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                ret = min(ret, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ret == n + 1 ? 0 : ret;
    }
};