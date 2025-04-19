#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> hash_s, hash_t;

    string minWindow(string s, string t) {
        for (char& ch: t) ++hash_t[ch];

        int left = 0, right = 0, minLen = INT_MAX, start = -1;
        int require = hash_t.size(), formed = 0;

        while (right < s.size()) {
            char right_ch = s[right];
            if (hash_t.count(right_ch)) {
                ++hash_s[right_ch];
                if (hash_s[right_ch] == hash_t[right_ch]) ++formed;
            }
            
            while (formed == require && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char left_ch = s[left];
                if (hash_t.count(left_ch)) {
                    if (hash_s[left_ch] == hash_t[left_ch]) --formed;
                    --hash_s[left_ch];
                }
                ++left;
            }
            ++right;
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};