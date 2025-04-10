#include<vector>
using namespace std;
#include<unordered_set>
#include<iostream>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            unordered_set<char> hash_set;
            for (int col = 0; col < 9; ++col) {
                char cur = board[row][col];
                if (isdigit(cur)) {
                    if (!hash_set.count(cur)) hash_set.insert(cur);
                    else return 0;
                }
            }
        }

        for (int row = 0; row < 9; ++row) {
            unordered_set<char> hash_set;
            for (int col = 0; col < 9; ++col) {
                char cur = board[col][row];
                if (isdigit(cur)) {
                    if (!hash_set.count(cur)) hash_set.insert(cur);
                    else return 0;
                }
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_set<char> hash_set;
                for (int i = row; i < row + 3; ++i) {
                    for (int j = col; j < col + 3; ++j) {
                        char cur = board[i][j];
                        if (isdigit(cur)) {
                            if (!hash_set.count(cur)) hash_set.insert(cur);
                            else return 0;
                        }
                    }
                }
            }
        }
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
