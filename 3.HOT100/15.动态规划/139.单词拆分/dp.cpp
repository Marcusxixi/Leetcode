#include<vector>
#include<string>
using namespace std;
#include<unordered_set>
#include<functional>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set dict(wordDict.begin(), wordDict.end());

        function<bool(int)> dfs = [&](int start) -> bool {
            if (start == n) return true;
            for (int end = start + 1; end <= n; ++end) {
                string word = s.substr(start, end - start);
                if (dict.count(word) && dfs(end)) return true;
            }
            return false;
        };
        return dfs(0);

        vector<bool> dp(n + 1);
        dp[n] = true;
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