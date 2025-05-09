#include<string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {

        auto voolve = [](char& ch) -> bool {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        int count = 0;
        for (int i = 0; i < k; ++i) {
            count += voolve(s[i]);
        }
        int ret = count;
        for (int i = k; i < s.length(); ++i) {
            count += voolve(s[i]) - voolve(s[i - k]);
            ret = max(ret, count);
        }
        return ret;
    }
};