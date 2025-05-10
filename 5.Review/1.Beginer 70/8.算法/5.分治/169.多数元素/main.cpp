#include<vector>
using namespace std;

class Solution {
public:

    int majority(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return nums[lo];

        int mid = lo + (hi - lo) / 2;
        int left = majority(nums, lo, mid);
        int right = majority(nums, mid + 1, hi);

        if (left == right) return left;

        // count each other
        int leftCount = 0, rightCount = 0;
        for (int i = lo; i <= hi; ++i) {
            if (nums[i] == left) ++leftCount;
            else if (nums[i] == right) ++rightCount;
        }
        return leftCount > rightCount ? left : right;
    }

    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
};