#include <iostream>
using namespace std;
#include <vector>
#include<unordered_set>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sCount(26);
        vector<int> pCount(26);
        vector<int> ret;
        int sSize = s.size(), pSize = p.size();
        if (sSize < pSize) return {};

        for (int i = 0; i < pSize; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }
        if (sCount == pCount) ret.emplace_back(0);

        for (int i = 0; i < sSize - pSize; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pSize] - 'a'];
            if (sCount == pCount) ret.emplace_back(i + 1);
        }
        return ret;
    }
};