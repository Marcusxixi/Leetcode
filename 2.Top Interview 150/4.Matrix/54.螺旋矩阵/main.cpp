#include<vector>
using namespace std;

class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
        vector<int> ret;
        while (left <= right && top <= bottom) {
            for (int col = left; col <= right; ++col) {
                ret.push_back(matrix[top][col]);
            }
            for (int row = top + 1; row <= bottom; ++row) {
                ret.push_back(matrix[row][right]);
            }
            // 防止 matrix 的 row == 1 或者 column == 1 的时候超出边界
            if (left < right && top < bottom) {
                for (int col = right - 1; col >= left; -- col) {
                    ret.push_back(matrix[bottom][col]);
                }
                for (int row = bottom - 1; row >= top + 1; --row) {
                    ret.push_back(matrix[row][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return ret;
    }
};