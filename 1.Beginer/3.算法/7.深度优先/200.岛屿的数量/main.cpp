#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<char>> & grid, int x, int y) {
        grid[x][y] = '0';
        if (x - 1 >= 0 && grid[x - 1][y] == '1') dfs(grid, x - 1, y);
        if (x + 1 < grid.size() && grid[x + 1][y] == '1') dfs(grid, x + 1, y);
        if (y - 1 >= 0 && grid[x][y - 1] == '1') dfs(grid, x, y - 1);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') dfs(grid, x, y + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;
        int sum = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    sum += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return sum;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}