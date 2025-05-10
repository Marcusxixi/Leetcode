#include<vector>
#include<functional>
using namespace std;

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        int n = nums.size();

        function<void(int)> dfs = [&](int index) -> void {
            if (index == n) {
                ret.push_back(path);
                return;
            }
            dfs(index + 1);

            path.push_back(nums[index]);
            dfs(index + 1);
            path.pop_back();
        };
        dfs(0);
        return ret;
    }
};