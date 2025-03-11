#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:

    void bfs( vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto[x, y] = q.front(); q.pop();
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                grid[x][y] = '0';
                q.push({x - 1, y});
                q.push({x + 1, y});
                q.push({x, y + 1});
                q.push({x, y - 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int sum = 0;

        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (grid[x][y] == '1') {
                    sum += 1;
                    bfs(grid, x, y);
                }
            }
        }
        return sum;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}