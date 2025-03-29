#include<iostream>
using namespace std;
#include<vector>
#include<functional>

class Solution {
public:

    bool isPalindromic(const string& words, int left, int right) {
        while (left < right) {
            if (words[left++] != words[right--]) return 0;
        }
        return 1;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        int n = s.size();
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ret.emplace_back(path);
                return;
            }

            for (int j = i; j < n; ++j) {
                if (isPalindromic(s, i, j)) {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }

        };
        dfs(0);
        return ret;
    }
};
