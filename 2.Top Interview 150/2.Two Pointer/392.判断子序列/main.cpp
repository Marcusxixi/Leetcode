#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int p_s = 0, p_t = 0;
        while (p_s < n && p_t < m) {
            if (s[p_s] == t[p_t]) ++p_s;
            ++p_t;
        }
        return p_s == n;
    }
};