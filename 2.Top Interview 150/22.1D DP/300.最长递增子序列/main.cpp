#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        // function<int(int, int)> dfs = [&] (int i, int pre) -> int {
        //     if (i == n) return 0;
        //     if (memo[i][pre + 1] != -1) return memo[i][pre + 1];
        //     int skip = dfs(i + 1, pre);
        //     int pick = 0;
        //     if (pre == -1 || nums[i] > nums[pre]) pick = dfs(i + 1, i) + 1;
        //     return memo[i][pre + 1] = max(pick, skip);
        // };
        // return dfs(0, -1);
        vector<int> dp(n, 1);

        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};