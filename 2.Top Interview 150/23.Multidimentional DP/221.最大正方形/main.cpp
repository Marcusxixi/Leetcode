#include<vector>
using namespace std;

class Solution {
private:
    int height;
    int width;
    vector<vector<int>> large;

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        height = matrix.size();
        width = matrix[0].size();
        int square = 0;
        large = vector<vector<int>>(height, vector<int>(width, 0));

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == '1') square = max(dfs(i, j, matrix), square);
            }
        }
        return square * square;
    }

    int dfs(int i, int j, vector<vector<char>>& matrix) {
        if (i >= height || j >= width || matrix[i][j] == '0') return 0;
        if (large[i][j] > 0) return large[i][j];

        int bottom = dfs(i + 1, j, matrix);
        int right = dfs(i, j + 1, matrix);
        int bottom_right = dfs(i + 1, j + 1, matrix);

        large[i][j] = min(min(bottom, right), bottom_right) + 1;
        return large[i][j];
    }
};