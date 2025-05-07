#include<string>
#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> memo(n, -1);

        function<int(int)> dfs = [&] (int start) -> int {
            if (start == n) return 0;

            if (memo[start] != -1) return memo[start];

            // 初始化最大长度
            int max_len = 0;
            int balance = 0; // 记录括号中的平衡

            // 从当前字符开始尝试递归计算有效的括号长度
            for (int i = start; i < n; ++i) {
                if (s[i] == '(') {
                    ++balance;
                } else if (s[i] == ')') {
                    --balance;
                }

                // 当平衡为 0，表示有一对有效括号
                if (balance == 0) max_len = max(max_len, i - start + 1);
                else if (balance < 0) break;
            }
            return memo[start] = max_len;
        };

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, dfs(i));
        }
        return ret;
    }
};