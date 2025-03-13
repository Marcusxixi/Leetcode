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
    int height;
    int width;
    int square = 0;
    vector<vector<char>> large;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        height = matrix.size();
        width = matrix[0].size();
        large = vector<vector<char>>(height, vector<char>(width, 0));

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == '1') {
                    square = max(square, dfs(matrix, i, j));
                }
            }
        }
        return square * square;
    }

private:
    int dfs(vector<vector<char>>&matrix, int row, int col) {
        if (row >= height || col >= width || matrix[row][col] == '0') {
            return 0;
        }
        if (large[row][col] > 0) return large[row][col];

        int bottom = dfs(matrix, row + 1, col);
        int right = dfs(matrix, row, col + 1);
        int right_bot = dfs(matrix, row + 1, col + 1);

        large[row][col] =  1 + min(min(bottom, right), right_bot);
        return large[row][col];
    }
};


int main(int argc, char const *argv[]){
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}};
    Solution sol;
     cout << sol.maximalSquare(matrix) << endl;
//    cout << 1 << endl;
    return 0;
}