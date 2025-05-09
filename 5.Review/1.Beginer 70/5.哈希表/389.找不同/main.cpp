#include<string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (int i = 0; i < t.length(); ++i) {
            ret += t[i] - '0';
        }

        for (int i = 0; i < s.size(); ++i) {
            ret -= s[i] - '0';
        }
        return ret + '0';
    }
};