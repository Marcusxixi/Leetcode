#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        int n = candidates.size();

        function<void(int, int)> dfs = [&](int index, int remain) {
            if (index == n || remain < 0) return;
            if (remain == 0) {
                ret.emplace_back(path);
                return;
            }
            dfs(index + 1, remain);
            
            path.emplace_back(candidates[index]);
            dfs(index, remain - candidates[index]);
            path.pop_back();
        };
        dfs(0, target);
        return ret;
    }
};