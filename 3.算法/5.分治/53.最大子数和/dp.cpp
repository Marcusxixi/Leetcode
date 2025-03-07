#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:


    int maxSubArray(vector<int>& nums) {
        int pre = 0, ret = nums[0];
        for (auto num : nums) {
            pre = max(pre + num, num);
            ret = max(pre, ret);
        }
        return ret;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ret = sol.maxSubArray(nums);
    cout << ret << endl;
    return 0;
}