#include<string>
using namespace std;
#include<unordered_map>
#include<stack>

class Solution {
public:
    bool isValid(string s) {

        int top = -1;
        for (char& ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                s[++top] = ch;
            } else {
                // 当前的栈为空时
                if (top < 0) return false;
                if ((ch == ')' && s[top] != '(') ||
                    (ch == ']' && s[top] != '[') ||
                    (ch == '}' && s[top] != '{')) return false;
                --top;
            }
        }
        // 检查栈是否为空
        return top == -1;
    }
};