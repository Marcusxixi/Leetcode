#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0, left = 0, right = height.size() - 1;
        while(left < right) {
            ret = height[left] < height[right] ?
                max(ret, (right - left) * height[left++]):
                max(ret, (right - left) * height[right--]);
        }
        return ret;
    }
};