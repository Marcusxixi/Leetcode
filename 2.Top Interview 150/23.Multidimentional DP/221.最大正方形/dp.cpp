#include<vector>
using namespace std;

class Solution {

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();

        vector<vector<int>> dp(height, vector<int>(width, 0));
        int side = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                side = max(side, dp[i][j]);
            }
        }
        return side * side;
    }
};