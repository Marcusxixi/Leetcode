#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        string sub_str = "";
        for (int i = 0; i < s.length(); ++i) {
            while (sub_str.find(s[i]) != string::npos) {
                sub_str.erase(0, 1);
            }
            sub_str += s[i];
            ret = max((int)sub_str.length(), ret);
        }
    }
};