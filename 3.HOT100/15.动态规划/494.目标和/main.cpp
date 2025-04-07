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
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));
        
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0) {
                if (c == 0) return 1;
                else return 0;
            }
            if (memo[i][c] != -1) return memo[i][c];
            if (c < nums[i]) return dfs(i - 1, c);
            return memo[i][c] = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
        return dfs(n - 1, target);
    }
};