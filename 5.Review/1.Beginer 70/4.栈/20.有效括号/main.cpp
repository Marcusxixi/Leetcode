#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, char> hash_map = {{')', '('},
                                          {']', '['},
                                          {'}', '{'}};
    stack<char> stk;
    bool isValid(string s) {
        for (char& ch: s) {
            if (hash_map.count(ch)) {
                if (stk.empty() || stk.top() != hash_map[ch]) return false;
                stk.pop();
            } else stk.push(ch);
        }
        return stk.size() == 0;
    }
};