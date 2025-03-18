#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int left = 0;
        int right = height.size() - 1;
        int pre_max = 0;
        int suf_max = 0;
        while (left <= right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                ret += pre_max - height[left];
                ++left;
            } else {
                ret += suf_max - height[right];
                --right;
            }
        }
        return ret;
    }
};