#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i = nums.size(); ++i) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};