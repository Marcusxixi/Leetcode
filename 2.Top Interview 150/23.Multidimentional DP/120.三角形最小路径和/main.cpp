#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        function<int(int, int)> dfs = [&] (int i, int j) -> int {
            if (i == n) return 0;
            if (memo[i][j] != INT_MAX) return memo[i][j];
            return memo[i][j] = min(dfs(i + 1, j), dfs(i + 1, j + 1)) + triangle[i][j];
        };
        return dfs(0, 0);


        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};