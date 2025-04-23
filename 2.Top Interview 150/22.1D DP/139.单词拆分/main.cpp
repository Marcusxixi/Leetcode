#include<string>
#include<vector>
using namespace std;
#include<unordered_set>
#include<unordered_map>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> cache;
        
        int n = s.size();

        function<bool(int)> dfs = [&] (int start) -> bool {
            if (start == n) return true;
            for (int end = start + 1; end <= n; ++end) {
                string word = s.substr(start, end - start);
                if (dict.count(word) && dfs(end)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0);
    }
};