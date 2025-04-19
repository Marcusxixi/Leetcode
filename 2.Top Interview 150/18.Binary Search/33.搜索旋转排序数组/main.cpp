#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            // 表示 nums[0] 到 nums[mid] 是升序的
            if (nums[0] <= nums[mid]) {
                // 判断target 在不在这个区间内
                if (nums[0] <= target && target < nums[mid]) right = mid -1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};