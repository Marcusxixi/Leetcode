#include<vector>
#include<iostream>
using namespace std;

class Solution {

    static constexpr int direction[4][3] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};

        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int total = row * col;
        vector<int> ret(total);
        int r = 0, c = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; ++i) {
            ret[i] = matrix[r][c];
            visited[r][c] = true;
            int nextRow = r + direction[directionIndex][0];
            int nextCol = c + direction[directionIndex][1];
            if (nextRow < 0 || nextRow > row || nextCol < 0 || nextCol > col || visited[nextRow][nextCol]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            r += direction[directionIndex][0];
            c += direction[directionIndex][1];
        }
        return ret;
    }
};