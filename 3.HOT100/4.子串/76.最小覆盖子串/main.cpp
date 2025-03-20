#include<iostream>
using namespace std;

class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check() {
        for(auto& p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(char& ch: t) {
            ++ori[ch];
        }

        int left = 0, right = -1;
        int currLen = INT_MAX, ansL = -1;

        //右指针拓展窗口
        while(right < int(s.size())) {
            //遇到的每一个 t 里面的字符都记录他的数值
            if (ori.count(s[++right])) {
                ++cnt[s[right]];
            }
            //当 check 返回 true 的时候，当前窗口已经包含所有需要字符
            //然后记录当前最小长度
            //最后尝试缩小 left 的边界
            while(check() && left <= right) {
                if (right - left < currLen) {
                    currLen = right - left + 1;
                    ansL = left;
                }
                if (ori.count(s[left])) {
                    --cnt[s[left]];
                }
                ++left;
            }
        }
        // 如果找不到满足条件的窗口则返回 "",否则返回[ansL, currLen]
        return ansL == -1 ? "" : s.substr(ansL, currLen);
    }
};