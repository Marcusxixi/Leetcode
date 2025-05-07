#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int top = -1;
        for (char& ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') s[++top] = ch;
            else {
                if (top < 0) return false;
                if (ch == ')' && s[top] != '(' ||
                    ch == ']' && s[top] != '[' ||
                    ch == '}' && s[top] != '{') return false;
                --top;
            }
        }
        return top == -1;
    }
};