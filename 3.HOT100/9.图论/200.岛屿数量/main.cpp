#include<vector>
using namespace std;
#include<iostream>


class Solution {
public:
    int ret = 0;

    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = 0;
        if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if (row + 1 < grid.size() && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
    }


    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    ++ ret;
                    dfs(grid, row, col);
                }
            }
        }
        return ret;
    }
};