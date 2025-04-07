#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int repeat_idx = 2;
        for (int right = 2; right < n; ++right) {
            if (nums[right] != nums[repeat_idx - 2]) {
                nums[repeat_idx] = nums[right];
                ++repeat_idx;
            }
        }
        return repeat_idx;
    }
};