#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        function<void(int)> dfs = [&](int index) -> void {
            if (index == n) {
                ret.emplace_back(nums);
                return;
            }
            for (int j = index; j < n; ++j) {
                // path[index] = nums[j];
                swap(nums[index], nums[j]);
                dfs(index + 1);
                swap(nums[index], nums[j]);
            }
        };
        dfs(0);
        return ret;
    }
};