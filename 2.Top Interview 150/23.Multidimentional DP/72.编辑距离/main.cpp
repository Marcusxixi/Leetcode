#include<string>
#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        function<int(int, int)> dfs = [&] (int i, int j) -> int {
            if (i == n) return m - j;
            if (j == m) return n - i;

            if (memo[i][j] != -1) return memo[i][j];

            if (word1[i] == word2[j]) return dfs(i + 1, j + 1);
            
            int insertOp = dfs(i, j + 1) + 1;
            int deleteOp = dfs(i + 1, j) + 1;
            int replaceOp = dfs(i + 1, j + 1) + 1;
            return memo[i][j] = min({insertOp, deleteOp, replaceOp});
        };
        return dfs(0, 0);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // 初始化边界
        for (int i = 0; i <= n; ++i) dp[i][0] = i;
        for (int j = 0; j <= m; ++j) dp[0][j] = j;

        // 填表
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insertOp = dp[i][j - 1] + 1;
                    int deleteOp = dp[i - 1][j] + 1;
                    int replaceOp = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }
        return dp[n][m];
    }
};