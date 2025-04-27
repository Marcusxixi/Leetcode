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
    }
};