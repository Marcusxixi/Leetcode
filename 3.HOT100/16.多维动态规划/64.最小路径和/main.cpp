#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) dp[0][j] += dp[0][j - 1];
                else if (j == 0) dp[i][0] += dp[i - 1][0];
                else dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};