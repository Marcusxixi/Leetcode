#include<vector>
#include<functional>
#include<numeric>
using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 假设 所有正数的和 = p, 那么所有负数的和 q = sum - p
        // 所以 p - q = target 2p = t + sum -> p = (t + s) / 2
        // 同等于从 nums 中选择一些数字，使得这些数字的和恰好等于 (t + s) / 2
        target += accumulate(nums.begin(), nums.end(), 0);
        // 如果 t + s 是奇数，则这个目标和不成立
        if (target < 0 || target % 2) return 0;
        target /= 2;
        int n = nums.size();

        vector<vector<int>> f(2, vector(target + 1, 0));
        f[0][0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int c = 0; c < target + 1; ++c) {
                if (c < nums[i]) {
                    // 这里利用了滚动数组的原理节省空间
                    // 因为 f(i) = f(i - 1) 只需要前面一个的值，再往前的值不需要
                    f[(i + 1) % 2][c] = f[i % 2][c];
                }
                else f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]];
            }
        }
        return f[n % 2][target];
    }
};