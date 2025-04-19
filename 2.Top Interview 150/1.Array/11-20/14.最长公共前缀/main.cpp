#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (! n) return "";
        string prefix = strs[0];
        for (int i = 1; i < n; ++i) {
            prefix = compare(prefix, strs[i]);
            if (!prefix.size()) break;
        }
        return prefix;
    }

    string compare(string& s1, string& s2) {
        int length = min(s1.size(), s2.size());
        int index = 0;
        while (index < length && s1[index] == s2[index]) ++index;
        return s1.substr(0, index);
    }
};