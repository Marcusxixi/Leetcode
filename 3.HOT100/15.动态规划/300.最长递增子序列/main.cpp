#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        function<int(int, int)> dfs = [&] (int i, int pre) -> int {
            if (i == n) return 0;
            int skip = dfs(i + 1, pre);
            int pick = 0;
            if (pre == -1 || nums[i] > nums[pre]) pick = dfs(i + 1, i) + 1;
            return max(pick, skip);
        };
        return dfs(0, -1);
    }
};