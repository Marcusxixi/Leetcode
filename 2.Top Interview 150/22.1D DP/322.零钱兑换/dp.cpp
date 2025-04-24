#include<vector>
using namespace std;
#include<functional>
#include<unordered_map>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector(amount + 1, -1));

        function<int(int, int)> dfs = [&] (int i, int c) -> int {
            if (i < 0) return c == 0 ? 0 : INT_MAX;

            if (memo[i][c] != -1) return memo[i][c];

            if (c < coins[i]) return dfs(i - 1, c);
            int pick = dfs(i, c - coins[i]);
            int notPick = dfs(i - 1, c);
            if (pick != INT_MAX) ++pick;
            return memo[i][c] = min(pick, notPick);
        };

        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= amount; ++c) {
                if (c < coins[i]) dp[i + 1][c] = dp[i][c];
                else dp[i + 1][c] = min(dp[i + 1][c - coins[i]], dp[i][c]);
            }
        }
        return dp[n][amount];



        int ret = dfs(n - 1, amount);
        return ret == INT_MAX ? -1 : ret;
    }
};

// f[i][c] = min( f[i][c - w[i]], f[i - 1][c] )

// f[i + 1][c] = min( f[i + 1][c - w[i]], f[i][c] )