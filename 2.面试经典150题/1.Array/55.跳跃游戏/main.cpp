#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            far = max(far, i + nums[i]);
            if (far <= i) return false;
        }
        return true;
    }
};