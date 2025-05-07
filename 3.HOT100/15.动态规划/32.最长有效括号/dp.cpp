#include<string>
#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<int> dp(n, 0);
        int max_len = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // 匹配到一个括号 当前长度是 2 + dp[i - 2]
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    // 匹配到 ')(...)' 即如果 i - dp[i - 1] - 1 是 '('，那么更新 dp[i]
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                }
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};