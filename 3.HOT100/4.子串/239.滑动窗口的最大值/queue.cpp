#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>q;
        for (int i = 0; i < k; ++i) {
            // Queue最前面的永远是最大的index,单调队列
            while(!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        //由于是单调队列，所以只需要将第一位存入结果即可
        vector<int> ret = {nums[q.front()]};
        for(int i = k; i < n; ++i) {
            while(!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            // 当队首元素已经不在滑动窗口的范围内时，将其踢出
            while (q.front() <= i - k) q.pop_front();
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};