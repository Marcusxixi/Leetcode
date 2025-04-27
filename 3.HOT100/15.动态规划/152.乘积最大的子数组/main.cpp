#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ret = nums[0];
        function<pair<int, int>(int)> dfs = [&] (int i) -> pair<int, int> {
            if (i == n) return {1, 1};

            auto next = dfs(i + 1);
            int max_p = next.first;
            int min_p = next.second;

            int cur_max = max({nums[i], nums[i] * max_p, nums[i] * min_p});
            int cur_min = min({nums[i], nums[i] * max_p, nums[i] * min_p});

            ret = max(ret, cur_max);
            return {cur_max, cur_min};
        };
        dfs(0);
        return ret;
    }
};