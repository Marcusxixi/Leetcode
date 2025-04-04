#include<vector>
using namespace std;
#include<functional>
#include<unordered_map>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        int f0 = 0, f1 = 0;
        for (int i = 0; i < n; ++i) {
            int newF = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = newF;
        }
        return f1;
    }
};