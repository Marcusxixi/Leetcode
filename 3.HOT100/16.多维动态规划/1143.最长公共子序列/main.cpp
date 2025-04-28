#include<string>
#include<functional>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length() - 1, len2 = text2.length() - 1;

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || j < 0) return 0;

            if (text1[i] == text2[j]) return dfs(i - 1, j - 1) + 1;

            return max(dfs(i - 1, j), dfs(i, j - 1));
        };
        return dfs(len1, len2);

        int n  = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};