#include<vector>
using namespace std;
#include<unordered_set>
#include<iostream>

class Solution {
public:

    void print2DIntVector(int matrix[9][9]) {
        int row = 9;
        string result = "";
        for (int i = 0; i < row; ++i) {
            result += "{";
            int col = 9;
            for (int j = 0; j < col; ++j) {
                result += to_string(matrix[i][j]);
                if (j < col - 1) {
                    result += ", ";
                }
            }
            result += "}";
            if (i < row - 1) {
                result += ",\n";
            }
        }
        result += "\n";
        cout << result << endl;
    }

    void printSubboxes(int subboxes[3][3][9]) {
        // 遍历每个 3x3 子宫格
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << "Subbox (" << i << ", " << j << "): ";
                // 打印 9 个数字
                for (int k = 0; k < 9; ++k) {
                    cout << subboxes[i][j][k] << " ";
                }
                cout << endl;
            }
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];

        // 初始化数组
        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subboxes, 0, sizeof(subboxes));

        

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    int index = ch - '0' - 1;
                    ++rows[i][index];
                    ++columns[j][index];
                    ++subboxes[i / 3][j / 3][index];
                    if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) return 0;
                }
            }
        }

        print2DIntVector(rows);
        print2DIntVector(columns);
        printSubboxes(subboxes);
        return 1;
    }
};

vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.isValidSudoku(board) << endl;
    return 0;
}
