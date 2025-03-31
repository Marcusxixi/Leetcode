#include<vector>
using namespace std;
#include<iostream>
#include<functional>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> queens(n);
        vector<int> col(n);
        vector<int> diag1(n * 2 - 1); // 表示对角线 r + c 是否有皇后
        vector<int> diag2(n * 2 - 1); // 表示副对角线 r - c + (n - 1) 是否有皇后

                                     // 尝试在第 r 行放置皇后
        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                vector<string> board(n);
                for (int i = 0; i < n; ++i) {
                    board[i] = string(queens[i], '.') + 'Q' + string(n - 1 - queens[i], '.');
                }
                ret.push_back(board);
                return;
            }

            // 在(r, c) 放皇后
            for (int c = 0; c < n; ++c) {
                int rc = r - c + n - 1;
                if (!col[c] && !diag1[r + c] && !diag2[rc]) {
                    queens[r] = c;
                    col[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false;
                }
            }
        };
        dfs(0);
        return ret;
    }
};