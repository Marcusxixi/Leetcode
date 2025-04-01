#include<vector>
using namespace std;
#include<stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n);
        stack<int> stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int preIndex = stack.top();
                ret[preIndex] = i - preIndex;
                stack.pop();
            }
            stack.push(i);
        }
        return ret;
    }
};