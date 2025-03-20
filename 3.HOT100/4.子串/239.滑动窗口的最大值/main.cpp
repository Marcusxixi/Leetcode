#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n - k + 1);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i], i);
        }
        ret[0] = pq.top().first;

        for(int i = k; i < n; ++i) {
            pq.emplace(nums[i], i);
            while (pq.top().second <= i - k) pq.pop();
            ret[i - k + 1] = pq.top().first;
        }
        return ret;
    }
};