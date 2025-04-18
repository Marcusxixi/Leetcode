#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<bool> visit(n, false);
        vector<int> path;
        function<void()> dfs = [&]() -> void {
            if (path.size() == n) {
                ret.emplace_back(path);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (visit[i]) continue;
                path.push_back(nums[i]);
                visit[i] = true;
                dfs();
                visit[i] = false;
                path.pop_back();
            }
        };
        dfs();
        return ret;
    }
};