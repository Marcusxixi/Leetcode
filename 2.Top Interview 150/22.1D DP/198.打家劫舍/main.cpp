#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int f0 = 0, f1 = 0;
        for (int i = n - 1; i >= 0; --i) {
            int newF = max(f0, f1 + nums[i]);
            f1 = f0;
            f0 = newF;
        }
        return f0;
        
        // vector<int> f(n + 2, 0);
        // for (int i = n - 1; i >= 0; --i) {
        //     f[i] = max(f[i + 1], f[i + 2] + nums[i]);
        // }
        // return f[0];


        // vector<int> cache(n, -1);
        // function<int(int)> dfs = [&] (int i) -> int {
        //     if (i >= n) return 0;
        //     if (cache[i] != -1) return cache[i];
        //     int ret = max(dfs(i + 2) + nums[i], dfs(i + 1));
        //     cache[i] = ret;
        //     return ret;
        // };
        // return dfs(0);
    }
};