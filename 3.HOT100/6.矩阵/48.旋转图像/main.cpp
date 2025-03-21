#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

void print2DIntVector(vector<vector<int>>& matrix) {
    int row = matrix.size();
    string result = "{";
    for (int i = 0; i < row; ++i) {
        result += "{";
        int col = matrix[i].size();
        for (int j = 0; j < col; ++j) {
            result += to_string(matrix[i][j]);
            if (j < col - 1) {
                result += ", ";
            }
        }
        result += "}\n";
        if (i < row - 1) {
            result += ", ";
        }
    }
    result += "}\n";
    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    print2DIntVector(nums);
    sol.rotate(nums);
    print2DIntVector(nums);
    return 0;
}
