#include<vector>
using namespace std;
#include<functional>

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ret = 0;

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') return;
            grid[r][c] = '0';
            dfs(r + 1, c);
            dfs(r, c + 1);
            dfs(r - 1, c);
            dfs(r, c - 1);
        };

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++ret;
                    dfs(i, j);
                }
            }
        }
        return ret;
    }
};