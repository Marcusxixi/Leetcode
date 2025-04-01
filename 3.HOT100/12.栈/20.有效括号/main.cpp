#include<iostream>
using namespace std;
#include<stack>
#include<unordered_map>

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash_map = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stack;
        for (char& ch: s) {
            if (hash_map.count(ch)) {
                if ( stack.empty() || stack.top() != hash_map[ch]) return 0;
                else stack.pop();
            }
            else stack.push(ch);
        }
        return stack.empty();
    }
};