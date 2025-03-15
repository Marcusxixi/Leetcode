#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_square = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    max_square = max(max_square, dp[i][j]);
                }
            }
        }
        return max_square * max_square;
    }
};


int main(int argc, char const *argv[]){
    vector<vector<char>>matrix = {{'1','0'}, {'0', '1'}};
    Solution sol;
    cout << sol.maximalSquare(matrix) << endl;
    return 0;
}