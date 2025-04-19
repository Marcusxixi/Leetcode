#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ret = nums[0];
        for (int num: nums) {
            pre = max(num, pre + num);
            ret = max(pre , ret);
        }
        return ret;
    }
};