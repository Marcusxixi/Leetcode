#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int x = nums[high];
        while (low < high) {
            int mid = low + (high - low) / 2;
            // 值在左边包括 mid
            if (nums[mid] < x) high = mid;
            else low = mid + 1;
        }
        return nums[low];
    }
};