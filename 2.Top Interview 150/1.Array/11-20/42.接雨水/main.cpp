#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // preMax 从左边走到当前位置的最高的柱子的高度
        // posMax 从右边走到当前位置的最高的柱子的高度
        int n = height.size(), preMax = 0, posMax = 0;
        int left = 0, right = n - 1, ret =0;
        while (left < right) {
            // 左边最大的高度
            preMax = max(preMax, height[left]);
            // 右边最大的高度
            posMax = max(posMax, height[right]);
            if (preMax < posMax) {
                ret += preMax - height[left];
                ++left;
            } else {
                ret += posMax - height[right];
                --right;
            }
        }
        return ret;
    }
};