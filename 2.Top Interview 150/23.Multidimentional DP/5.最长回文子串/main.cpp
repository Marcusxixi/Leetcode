#include<string>
using namespace std;
#include<vector>
#include<functional>

class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> isPal(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));


        function<bool(int, int)> isPalindrome = [&] (int left, int right) -> bool {
            if (left >= right) return true;
            if (isPal[left][right] != -1) return isPal[left][right];
            if (s[left] == s[right]) return isPal[left][right] = isPalindrome(left + 1, right - 1);
            return isPal[left][right] = false;
        };

        int maxLen = 0;
        int startIdx = 0;

        function<void(int, int)> helper = [&] (int start, int end) -> void {
            if (start > end || visited[start][end]) return;
            visited[start][end] = true;

            if (isPalindrome(start, end)) {
                int len = end - start + 1;
                if (len > maxLen) {
                    maxLen = len;
                    startIdx = start;
                }
                return;
            }
            helper(start + 1, end);
            helper(start, end - 1);
        };


        helper(0, s.length() - 1);
        return s.substr(startIdx, maxLen);
    }
};