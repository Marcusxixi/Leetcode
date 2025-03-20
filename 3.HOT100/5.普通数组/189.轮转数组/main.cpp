#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ret(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ret[i] = nums[(i + k - 1) % nums.size()];
        }
    }
};