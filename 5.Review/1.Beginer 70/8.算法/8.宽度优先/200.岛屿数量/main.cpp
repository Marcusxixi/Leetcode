#include<vector>
#include<queue>
using namespace std;

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ret = 0;
        

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++ret;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto ij = q.front(); q.pop();
                        int row = ij.first, col = ij.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            grid[row - 1][col] = '0';
                            q.push({row - 1, col});
                        }
                        if (row + 1 < rows && grid[row + 1][col] == '1') {
                            grid[row + 1][col] = '0';
                            q.push({row + 1, col});
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            grid[row][col - 1] = '0';
                            q.push({row, col - 1});
                        }
                        if (col + 1 < cols && grid[row][col + 1] == '1') {
                            grid[row][col + 1] = '0';
                            q.push({row, col + 1});
                        }
                    }
                }
            }
        }
        return ret;
        
    }
};