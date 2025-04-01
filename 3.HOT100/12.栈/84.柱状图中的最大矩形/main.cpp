#include<vector>
using namespace std;
#include<climits>
#include<stack>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n); // 存储左右边界
        stack<int> mono_stack;         // 单调递增栈

        // 计算左边界
        for (int i = 0; i < n; ++i) {
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop(); // 栈顶柱子 >= 当前柱子，不满足递增性，弹出
            }
                // 记录左边第一个小于 heights[i]的索引
            left[i] = mono_stack.empty() ? -1 : mono_stack.top();
                // 压入当前索引
            mono_stack.push(i);
        }
        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            } 
            right[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, (right[i] - left[i] - 1) * heights[i]);
        }
        return ret;
    }
};