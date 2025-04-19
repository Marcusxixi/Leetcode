#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; ++i) {
            bool found = 1;
            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    found = 0;
                    break;
                }
            }
            if (found) return i;
        }
        return -1;
    }
};