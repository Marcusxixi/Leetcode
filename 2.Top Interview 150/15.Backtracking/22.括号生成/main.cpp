#include<vector>
#include<string>
#include<functional>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path(2 * n, 0);
        function<void(int, int)> dfs = [&] (int index, int left) {
            if (index == 2 * n) {
                ret.emplace_back(path);
                return;
            }

            if (left < n) {
                path[index] = '(';
                dfs(index + 1, left + 1);
            }
            
            if (index - left < left) {
                path[index] = ')';
                dfs(index + 1, left);
            }
        };
        dfs(0, 0);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> ret = sol.generateParenthesis(3);
    for (auto& str: ret) {
        cout << str << "   ";
    }
    cout << endl;
    return 0;
}
