#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target =  total / 2;
        int n = nums.size();

        vector<bool> dp(target + 1, false);
        dp[0] = 1;
        for (int& x: nums) {
            for (int t = target; t >= x; --t) {
                dp[t] = dp[t] || dp[t - x];
            }
        }
        return dp[target]; 

    }
};