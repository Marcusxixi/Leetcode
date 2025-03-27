#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [cur_row, cur_col] = q.front(); q.pop();

                for (auto& [dr, dc]: direction) {
                    int side_row = dr + cur_row, side_col = dc + cur_col;
                    if (side_row >=0 && side_row < rows && side_col >=0 && side_col < cols && grid[side_row][side_col] == 1) {
                        grid[side_row][side_col] = 2;
                        q.push({side_row, side_col});
                        --fresh;
                    }
                }
            }
            ++time;
        }
        return fresh == 0 ? time : -1;
    }
};