#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:

    int getMax(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];

        int mid = left + (right - left) / 2;
        int left_max = getMax(nums, left, mid);
        int right_max = getMax(nums, mid + 1, right);
        int cross_max = getCross(nums, left, right);
        return (max(max(left_max, right_max), cross_max));
    }

    int getCross(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;

        int left_sum = nums[mid];
        int left_max = left_sum; 
        for (int i = mid - 1; i >= left; i--) {
            left_sum += nums[i];
            left_max = max(left_max, left_sum);
        }

        int right_sum = nums[mid + 1];
        int right_max = right_sum;
        for (int i = mid + 2; i <= right; i++) {
            right_sum += nums[i];
            right_max = max(right_max, right_sum);
        }

        return max(max(left_max, right_max), left_max + right_max);

    }

    int maxSubArray(vector<int>& nums) {
        return getMax(nums, 0, nums.size() - 1);
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ret = sol.maxSubArray(nums);
    cout << ret << endl;
    return 0;
}