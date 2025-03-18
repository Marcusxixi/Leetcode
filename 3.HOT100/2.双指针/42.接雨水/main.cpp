#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>pre(n);
        pre[0] = height[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = max(height[i], pre[i - 1]);
        }
        
        vector<int>suf(n);
        suf[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = max(height[i], suf[i + 1]);
        } 
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += min(pre[i], suf[i]) - height[i];
        }
        return ret;
    }
};