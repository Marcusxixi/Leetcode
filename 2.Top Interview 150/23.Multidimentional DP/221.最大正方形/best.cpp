#include<vector>
using namespace std;

class Solution {

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();

        vector<int> dp(width, 0);
        int side = 0;

        for (int i = 0; i < height; ++i) {
            int top_left = 0;
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        top_left = dp[j];
                        dp[j] = 1;
                    } else {
                        int tmp = dp[j];
                        dp[j] = min({dp[j - 1], dp[j], top_left}) + 1;
                        top_left = tmp;
                    }
                    side = max(side, dp[j]);
                } else {
                    top_left = dp[j];
                    dp[j] = 0;
                }
            }
        }
        return side * side;
    }
};