#include<vector>
using namespace std;
#include<iostream>


void print2DIntVector(vector<vector<int>>& matrix) {
    int row = matrix.size();
    string result = "";
    for (int i = 0; i < row; ++i) {
        result += "{";
        int col = matrix[i].size();
        for (int j = 0; j < col; ++j) {
            result += to_string(matrix[i][j]);
            if (j < col - 1) {
                result += ", ";
            }
        }
        result += "}";
        if (i < row - 1) {
            result += ",\n";
        }
    }
    result += "\n";
    cout << result << endl;
}

class Solution {
public:

    void print2DIntVector(vector<vector<int>>& matrix) {
        int row = matrix.size();
        string result = "";
        for (int i = 0; i < row; ++i) {
            result += "{";
            int col = matrix[i].size();
            for (int j = 0; j < col; ++j) {
                result += to_string(matrix[i][j]);
                if (j < col - 1) {
                    result += ", ";
                }
            }
            result += "}";
            if (i < row - 1) {
                result += ",\n";
            }
        }
        result += "\n";
        cout << result << endl;
    }

    bool check(vector<vector<int>>& modifyGrid, vector<vector<int>>& grid, int row, int col) {
        if (row >= 0 && row < grid.size() && col >=0 && col < grid[0].size() && modifyGrid[row][col] == 1) {
            grid[row][col] = 2;
            return 1;
        }
        return 0;

    }

    int orangesRotting(vector<vector<int>>& grid) {
        int badTotal = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 2) ++badTotal;
            }
        } 
        int curBad;
        int time = 0;
        while (curBad != badTotal) {
            curBad = badTotal;
            vector<vector<int>> modifyGrid = grid;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (modifyGrid[i][j] == 2) {
                        if (check(modifyGrid, grid, i + 1, j)) ++curBad;
                        if (check(modifyGrid, grid, i - 1, j)) ++curBad;
                        if (check(modifyGrid, grid, i, j + 1)) ++curBad;
                        if (check(modifyGrid, grid, i, j - 1)) ++curBad;
                    }
                }
            }
            print2DIntVector(grid);
            if (curBad != badTotal) ++ time;
        }
        

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};



int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    grid = {{2,1,1}, {0,1,1}, {1,0,1}};
    grid = {{0, 2}};
    print2DIntVector(grid);
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}
