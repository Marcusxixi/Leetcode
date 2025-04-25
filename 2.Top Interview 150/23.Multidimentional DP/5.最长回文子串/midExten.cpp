#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLen = 1;

        auto expand = [&] (int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i); // 以 i 为中心查找奇数长度的回文串
            expand(i, i + 1); // 以 i 和 i + 1 为中心 查找偶数长度回文串
        }
        
        return s.substr(start, maxLen);

    }
};