#include<vector>
using namespace std;
#include<numeric>
#include<functional>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // p 为所有正整数之和
        // s - p 为所有负整数之和
        // p - (s - p) = t
        // 2p = t + s
        // p = (t + s) / 2
        // t + s 要为偶数且要大于 0
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2) return 0;
        target /= 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int capacity = 0; capacity < target + 1; ++capacity) {
                if (capacity < nums[i]) 
                    dp[i + 1][capacity] = dp[i][capacity]; // 当前装不下，只能不选
                else 
                    dp[i + 1][capacity] = dp[i][capacity] + dp[i][capacity - nums[i]];
                    // 当前可以选或不选

            }
        }
        return dp[n][target];

    }
};