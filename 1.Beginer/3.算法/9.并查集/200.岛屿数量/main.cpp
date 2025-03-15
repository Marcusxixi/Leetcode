#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class UnionFind {
public:
vector<int> root;
int count;
    
    UnionFind(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        root = vector<int>(row * col);
        count = row * col;
        for (int i = 0; i < root.size(); i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (x == root[x]) return root[x];
        else {
            root[x] = find(root[x]);
            return root[x];
        }
    }

    void unionXY(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            root[rootX] = rootY;
            count -= 1;
        }
    }
        
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if (grid.empty() || row == 0) return 0;

        UnionFind uf(grid);
        int water = 0;
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') water += 1;
                else {
                    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for(const auto& item : direction) {
                        int x = item.first + i;
                        int y = item.second + j;
                        if (x >= 0 && x < row && y >=0 && y < col && grid[x][y] == '1') {
                            uf.unionXY(x * col + y, i * col + j);
                        }
                    }
                }
            }
        }
        return uf.count - water;
    }
};





int main(int argc, char const *argv[]){
    vector<vector<char>> grid = {{'1','1','1','1','0'}, 
                                 {'1','1','0','1','0'}, 
                                 {'1','1','0','0','0'}, 
                                 {'0','0','0','0','0'}};
    Solution sol;
    cout << sol.numIslands(grid) << endl;;
    return 0;
}