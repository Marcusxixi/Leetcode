#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;
        int max_left = helper(nums, left, mid);
        int max_right = helper(nums, mid + 1, right);
        int crossMax = crossSum(nums, left, mid, right);
        return max({max_left, max_right, crossMax});
    }

    int crossSum(vector<int> &nums, int left, int mid, int right) {
        int leftSum = INT_MIN, sum = 0;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            leftSum = max(sum, leftSum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            rightSum = max(sum, rightSum);
        }

        return leftSum + rightSum;

    }
};