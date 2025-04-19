#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_arr[26];
        int t_arr[26];
        int len = s.length();
        if (len != t.length()) return false;
        for (int i = 0; i < len; ++i) {
            ++s_arr[s[i] - 'a'];
            ++t_arr[t[i] - 'a'];
        }
        return s_arr == t_arr;
    }
};