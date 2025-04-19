#include<vector>
using namespace std;
#include<stack>
#include<unordered_set>

class Solution {
public:
bool check(string& token) {
    return !(token == "+" || token == "-" || token == "*" || token == "/");
}

int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for (string& token: tokens) {
        if (check(token)) {
            nums.push(stoi(token));
        } else {
            int num2 = nums.top(); nums.pop();
            int num1 = nums.top(); nums.pop();

            switch(token[0]) {
                case '+':
                    nums.push(num1 + num2);
                    break;
                case '-':
                    nums.push(num1 - num2);
                    break;
                case '*':
                    nums.push(num1 * num2);
                    break;
                case '/':
                    nums.push(num1 / num2);
                    break;
            }


        }
    }
    return nums.top();
}
};