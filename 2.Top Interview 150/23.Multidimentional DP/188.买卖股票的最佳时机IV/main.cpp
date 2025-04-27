#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int index = n - 1; index >= 0; --index) {
            for (int can_buy = 1; can_buy >= 0; --can_buy) {
                for (int left = k; left >= 1; --left) {
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
        return dp[0][1][k];
    }
};