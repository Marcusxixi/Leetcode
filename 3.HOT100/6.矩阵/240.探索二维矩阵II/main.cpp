#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;

        while (col >= 0 && row <= m - 1) {
            if (matrix[row][col] == target) return true;

            if (target < matrix[row][col]) --col;
            else if (target > matrix[row][col]) ++row;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {{1,4,7,11,15}, {2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    matrix = {{-1, 3}};
    cout << sol.searchMatrix(matrix, 3) << endl; 
    return 0;
}
