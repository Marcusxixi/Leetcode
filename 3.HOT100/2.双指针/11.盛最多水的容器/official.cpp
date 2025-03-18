#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            height[left] < height[right] ?
                maxarea = max((right - left) * height[left++], maxarea):
                maxarea = max((right - left) * height[right--], maxarea);
        }
        return maxarea;
    }
};

int main(int argc, const char** argv) {
    vector<int> he = {5, 5};
    Solution sol;
    cout << sol.maxArea(he) << endl;
    return 0;
}