#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int val_idx = 0;
        for (int pointer = 0; pointer < nums.size(); ++ pointer) {
            if (nums[pointer] != val) {
                swap(nums[pointer], nums[val_idx]);
                ++val_idx;
            }
        }
        return val_idx;
    }
};