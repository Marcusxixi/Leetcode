#include<iostream>
#include<vector>
using namespace std;
#include<stack>

class Solution {
public:

    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            // 跳过空格
            if (s[start] != ' ') {
                //遇到非空格字符，说明已经是单词的新开头，如果 index != 0,说明已经处理过单词，需要加一个空格
                if (idx != 0) s[idx++] = ' ';
                int end = start;
                while(end < n && s[end] != ' ') s[idx++] = s[end++];
                // idx - (end - start)是这个单词的起始位置，idx 是结尾
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = " hello world ";
    cout << sol.reverseWords(s) << endl;
    return 0;
}
