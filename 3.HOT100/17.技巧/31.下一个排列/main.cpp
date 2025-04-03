#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;
        
        // 1.找到第一对 nums[i] < nums[i + 1]
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;

        // 2.如果找到了 nums[i], 接着找nums[j]并交换
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }

        // 3.翻转 i + 1 之后的部分
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};