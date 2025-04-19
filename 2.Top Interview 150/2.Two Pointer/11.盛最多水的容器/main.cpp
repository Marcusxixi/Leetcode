#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                maxArea = max(maxArea, height[left] * (right - left));
                left++;
            } else {
                maxArea = max(maxArea, height[right] * (right - left));
                right++;
            }
        }
    }
};