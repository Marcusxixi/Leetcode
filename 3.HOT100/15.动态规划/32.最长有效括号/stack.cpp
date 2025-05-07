#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else { // 这里s[i] 等于 ')'
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ret = max(ret, i - stk.top());
                }
            }
        }
        return ret;
    }
};