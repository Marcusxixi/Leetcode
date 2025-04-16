#include<vector>
using namespace std;
#include<iostream>

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int d = 0; d < 4; ++d) {
            int row = i + dx[d];
            int col = j + dy[d];
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;
            if (grid[row][col] == '1') dfs(grid, row, col);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++ret;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };    
    Solution sol;
    sol.dfs(grid, 0, 0);
    return 0;
}
