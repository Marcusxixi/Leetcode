#include<stack>
using namespace std;
#include<functional>

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> stack;
        string res = "";
        int multi = 0;


        for (char& ch: s) {
            if (ch == '[') {
                stack.push({multi, res});
                multi = 0;
                res = "";
            } else if (ch == ']') {
                auto [curmulti, last_res] = stack.top(); stack.pop();
                string tmp = "";
                for (int i = 0; i < curmulti; ++i) tmp += res;
                res = last_res + tmp;
            } else if (ch - '0' <= 9 && ch - '0' >= 0) multi = multi * 10 + ch - '0';
            else res += ch;
        }
        return res;
    }
};