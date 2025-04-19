#include<vector>
using namespace std;
#include<deque>

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int num: nums) {
            total += num;

            curMax = max(num, num + curMax);
            maxSum = max(maxSum, curMax);

            curMin = min(num, num + curMin);
            minSum = min(curMin, minSum);
        }
        // 全是负数
        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};