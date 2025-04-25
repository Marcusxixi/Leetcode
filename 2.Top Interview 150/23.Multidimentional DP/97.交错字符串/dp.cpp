#include<string>
using namespace std;
#include<vector>
#include<functional>
// #include<unordered_map>

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        if (n + m != t) return false;

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        function<bool(int, int)> dfs = [&] (int i, int j) -> bool {
            int k = i + j;
            if (k == t) return true;

            if (memo[i][j] != -1) return memo[i][j];
            bool ret = false;
            if (i < n && s1[i] == s3[k]) {
                ret = dfs(i + 1, j);
            }
            if (!ret && j < m && s2[j] == s3[k]) {
                ret = dfs(i, j + 1);
            }
            return memo[i][j] = ret;
        };
        return dfs(0, 0);

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int k = i + j;
                if (i > 0 && s1[i - 1] == s3[k - 1]) dp[i][j] = dp[i - 1][j];
                if (!dp[i][j] && j > 0 && s2[j - 1] == s3[k - 1]) dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};

