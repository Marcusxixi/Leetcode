#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int dp[n + 1][2][3];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> dfs = [&] (int index, int can_buy, int left) -> int {
            if (index == n || left == 0) return 0;

            if (dp[index][can_buy][left] != -1) return dp[index][can_buy][left];

            int ret = 0;
            if (can_buy) {
                int buy = -prices[index] + dfs(index + 1, 0, left);
                int skip = dfs(index + 1, 1, left);
                ret = max(buy, skip);
            } else {
                int sell = prices[index] + dfs(index + 1, 1, left - 1);
                int skip = dfs(index + 1, 0, left);
                ret = max(sell, skip);
            }

            return dp[index][can_buy][left] = ret;
        };
        return dfs(0, 1, 2);


        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; --index) {
            for (int can_buy = 1; can_buy >= 0; ++can_buy) {
                for (int left = 1; left <= 2; ++left) {
                    if (can_buy) {
                        dp[index][can_buy][left] = max(
                            -prices[index] + dp[index + 1][0][left],
                            dp[index + 1][1][left]
                        );
                    } else {
                        dp[index][can_buy][left] = max(
                            prices[index] + dp[index + 1][1][left - 1],
                            dp[index + 1][0][left]
                        );
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};