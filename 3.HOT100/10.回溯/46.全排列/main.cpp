#include<vector>
using namespace std;
#include<iostream>
#include<unordered_set>

class Solution {

    void print1DIntVector(vector<int>& nums) {      
        string result = "{";
        for (int num: nums) {
            result += to_string(num) + ", ";
        }
        result = result.substr(0, result.size() - 2);
        result += "}";
        cout << result << endl;
    }
public:
    vector<vector<int>> ret;

    

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path(n), on_path(n);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ret.push_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {
                    path[i] = nums[j];
                    on_path[j] = 1;
                    dfs(i + 1);
                    on_path[j] = 0;
                }
            }
            
        };
        dfs(0);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int>nums = {1,2,3};
    sol.permute(nums);
    return 0;
}