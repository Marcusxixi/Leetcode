#include<vector>
using namespace std;
#include<stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> idx;
        vector<int> ret(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while(!idx.empty() && temperatures[i] >= temperatures[idx.top()]) {
                idx.pop();
            }
            if (!idx.empty()) ret[i] = idx.top() - i;
            idx.push(i);
        }
        return ret;
    }
};