#include<vector>
#include<functional>
#include<numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 假设 所有正数的和 = p, 那么所有负数的和 q = sum - p
        // 所以 p - q = target 2p = t + sum -> p = (t + s) / 2
        // 同等于从 nums 中选择一些数字，使得这些数字的和恰好等于 (t + s) / 2
        target += accumulate(nums.begin(), nums.end(), 0);
        // 如果 t + s 是奇数，则这个目标和不成立
        if (target < 0 || target % 2) return 0;
        target /= 2;
        int n = nums.size();

        vector<vector<int>> memo(n, vector(target + 1, -1));
        function<int(int, int)> dfs = [&] (int i, int c) -> int {
            if (i < 0) return c == 0 ? 1 : 0;
            if (memo[i][c] != -1) return memo[i][c];
            if (c < nums[i]) return memo[i][c] = dfs(i - 1, c);
            return memo[i][c] = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
        return dfs(n - 1, target);
    }
};
