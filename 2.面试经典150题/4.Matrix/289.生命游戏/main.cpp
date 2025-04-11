#include<vector>
using namespace std;

class Solution {
public:
    int count(vector<vector<int>>& board, int i, int j) {
        int rows = board.size(), cols = board[0].size();
        int ret = 0;
        int neighbors[3] = {0, 1, -1};

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (row == 0 && col == 0) continue;
                int r = i + neighbors[row];
                int c = j + neighbors[col]; 
                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    continue;
                }
                if (abs(board[r][c]) == 1) ++ret;
            }
        }

        return ret;
    }


    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int cnt = count(board, i, j);
                // 以前活 现在死
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3)) { 
                    board[i][j] = -1;
                }
                // 以前死，现在活
                if (board[i][j] == 0 && cnt == 3) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] <= 0) board[i][j] = 0;
                else board[i][j] = 1;
            }
        }
    }
};