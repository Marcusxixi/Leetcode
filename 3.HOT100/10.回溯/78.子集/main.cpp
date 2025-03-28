#include<vector>
#include<functional>
#include<iostream>
using namespace std;

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        int n = nums.size();
        function<void(int)> dfs = [&](int i) {
            ret.push_back(path);
            if (i == n) return;
            for (int j = i; j < n; ++j) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ret;
    }
};

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

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    Solution sol;
    vector<vector<int>> ret = sol.subsets(nums);
    print2DIntVector(ret);
    return 0;
}
