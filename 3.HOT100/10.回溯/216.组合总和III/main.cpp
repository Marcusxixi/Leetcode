#include<vector>
using namespace std;
#include<functional>
#include<iostream>

class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> ret;
            vector<int> path;
            function<void(int, int)> dfs = [&](int i, int t) {
                int d = k - path.size();
                if (t < 0 || t > (i * 2 - d + 1) * d / 2) return;
                if (path.size() == k) {
                    ret.push_back(path);
                    return;
                }
    
                for (int j = i; j > d - 1; --j) {
                    path.push_back(j);
                    dfs(j - 1, t - j);
                    path.pop_back();
                }
            };
            dfs(9, n);
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
    Solution sol;
    int k = 9, n = 45;
    vector<vector<int>> ret = sol.combinationSum3(k, n);
    print2DIntVector(ret);
    return 0;
}
