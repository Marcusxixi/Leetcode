#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for(int num: nums) {
            pre = max(pre + num, num);
            maxAns = max(pre, maxAns);
        }
        return maxAns;
    }
};