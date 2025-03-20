#include<iostream>
using namespace std;

class Solution {
public:
    unordered_map<char, int> hash_s, hash_t;
    
    bool check() {
        for(auto& it: hash_t) {
            if (hash_s[it.first] < it.second) return 0;
        }
        return 1;
    }

    string minWindow(string s, string t) {
        for (char& ch: t) {
            ++hash_t[ch];
        }

        int left = 0, right = -1;
        int minLen = INT_MAX, ansL = -1;

        while(right < (int)s.size()) {
            if (hash_t.count(s[++right])) {
                ++hash_s[s[right]];
            }

            while (check() && left <= right) {
                if (right - left < minLen) {
                    minLen = right - left + 1;
                    ansL = left;
                }
                if (hash_t.count(s[left])) {
                    --hash_s[s[left]];
                }
                ++left;
            }
        } 
        return ansL == -1 ? "" : s.substr(ansL, minLen);
    }
};