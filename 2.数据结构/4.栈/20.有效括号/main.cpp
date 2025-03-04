#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash_table = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> char_stack;
        for (char ch : s){
            if(hash_table.count(ch)){
                //找到了反括号 开始遍历栈内的元素
                // 栈里面装的是正括号，如果找到一个反括号后栈里面没有东西，代表这个括号不对，或者栈顶元素不能匹配当前括号就返回false
                if (char_stack.empty() || char_stack.top() != hash_table[ch]) {
                    return false;
                }
                char_stack.pop();
            }
            else {
                char_stack.push(ch);
            }
        }
        return char_stack.empty();
    }
};



int main(int argc, char const *argv[]){
    string s = "(){}[]";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}