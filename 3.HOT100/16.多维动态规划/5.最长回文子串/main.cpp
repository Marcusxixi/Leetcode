#include<string>
#include<functional>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 1;
        int start = 0;

        function<void(int, int)> expand = [&] (int left, int right) {
            while (left >= 0 && right <= n - 1 && s[left] == s[right]) {
                if (right - left + 1 > max_len) {
                    max_len = right - left + 1;
                    start = left;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, max_len);
    }
};