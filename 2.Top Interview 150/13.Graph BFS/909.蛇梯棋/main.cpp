#include<vector>
#include<queue>
using namespace std;

class Solution {
public:

    pair<int, int> id2rc(int num, int n) {
        int row = n - 1 - (num - 1) / n;
        int col = (num - 1) / n;
        if ((n - row) & 2 == 0) {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n * n + 1, false);
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (int i = 1; i <= 6; ++i) {
                int nxt = p.first + i;
                if (nxt > n * n) break;
                auto rc = id2rc(nxt, n);
                if (board[rc.first][rc.second] > 0) {
                    nxt = board[rc.first][rc.second];
                }
                if (nxt == n * n) return p.second + 1;
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1);
                }
            }
        }
        return -1;
    }
};