#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 1;
        int k = 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == 1){
                ++k;
            } else if (nums[i + 1] == nums[i]){
                continue;
            } else {
                ret = max(ret, k);
            }
        }
        return max(k, ret);
    }
};

int main(int argc, const char** argv) {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution sol;
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}