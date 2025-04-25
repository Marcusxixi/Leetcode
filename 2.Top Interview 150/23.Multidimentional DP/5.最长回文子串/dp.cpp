#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // 枚举子串长度
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) dp[i][j] = true;
                }
            }
        }
    }
};