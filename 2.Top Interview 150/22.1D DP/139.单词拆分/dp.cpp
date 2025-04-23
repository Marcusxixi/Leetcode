#include<string>
#include<vector>
using namespace std;
#include<unordered_set>
#include<unordered_map>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        // 从后往前开始 一个单词是 i -> j 先要判断 j 的位置是不是 1 并且 i -> j是一个单词的时候 才将 i 位置 = 1
        // 找到后立马 break 减少循环次数
        // 最后判断最前面是不是 true 因为必须后面都是 true 的时候才能满足最前面的是 true
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (dp[j] && dict.count(s.substr(i, j - i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};