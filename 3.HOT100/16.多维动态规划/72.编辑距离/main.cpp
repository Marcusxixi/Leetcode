#include<string>
using namespace std;
#include<functional>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();

        function<int(int, int)> dfs = [&] (int i, int j) -> int {

            if (i == l1) return l2 - j;
            if (j == l2) return l1 - i;

            if (word1[i] == word2[j]) return dfs(i + 1, j + 1);
            return min({
                dfs(i + 1, j) + 1,
                dfs(i, j + 1) + 1,
                dfs(i + 1, j + 1) + 1
            });
        };

        return dfs(0, 0); 


        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i <= l1; ++i) dp[i][l2] = l1 - i;
        for (int j = 0; j <= l2; ++j) dp[l1][j] = l2 - j;

        for (int i = l1 - 1; i >= 0; --i) {
            for (int j = l2 - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1];
                else {
                    dp[i][j] = min({
                        dp[i + 1][j] + 1,
                        dp[i][j + 1] + 1,
                        dp[i + 1][j + 1] + 1
                    });
                }
            }
        }
        return dp[0][0];

    }
};