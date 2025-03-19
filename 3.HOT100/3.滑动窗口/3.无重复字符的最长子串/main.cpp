#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        string sub_str = "";
        unordered_set<char> hash_set;
        for (char& ch: s) {
            while (sub_str.find(ch) != string::npos) {
                sub_str.erase(0, 1);
            }
            sub_str += ch;
            ret = max(ret, (int)sub_str.size());
            
        }
        return ret;
    }
};