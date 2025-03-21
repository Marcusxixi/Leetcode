#include<iostream>
#include<vector>
using namespace std;
#include<unordered_set>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        int row = matrix.size(), col = matrix[0].size();
        //遍历每一row，看 col0 是否存在 0
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) col0 = true; 
        }
        //遍历每一col，看 row0 是否存在 0
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) row0 = true;
        }
        // 从[1][1]开始遍历，如果有 0 则标记第 0 行
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 从[0][0]开始遍历，如果第 0row 和第 0col 有存在 0，那么这一整列都需要变成 0
        for(int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][0] == 0) matrix[i][j] = 0;
                if (matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (row0) {
            for (int j = 0; j < col; ++j) {
                matrix[0][col] = 0;
            }
        }

        if (col0) {
            for (int i = 0; i < row; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

void print2DIntVector(vector<vector<int>>& matrix) {
    int row = matrix.size();
    string result = "{";
    for (int i = 0; i < row; ++i) {
        result += "{";
        int col = matrix[i].size();
        for (int j = 0; j < col; ++j) {
            result += to_string(matrix[i][j]);
            if (j < col - 1) {
                result += ", ";
            }
        }
        result += "}";
        if (i < row - 1) {
            result += ", \n";
        }
    }
    result += "}\n";
    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    print2DIntVector(matrix);
    Solution sol;
    sol.setZeroes(matrix);
    print2DIntVector(matrix);
    return 0;
}
