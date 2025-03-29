#include<vector>
using namespace std;
#include<functional>
#include<numeric>


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        int n = candidates.size();

        function<void(int, int)> dfs = [&](int i, int remain) {
            if (i == candidates.size()) return;
            if (remain == 0) {
                ret.push_back(path);
                return;
            }

            dfs(i +1, remain);
            if (remain >= candidates[i]) {
                path.push_back(candidates[i]);
                dfs(i, remain - candidates[i]);
                path.pop_back();
            } 

        };
        dfs(0, target);
        return ret;
    }
};