#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path = "";
        function<void(int, int)> dfs = [&](int left, int right) {
            if (path.length() == 2 * n) {
                ret.push_back(path);
                return;
            }
            if (right > left || left > n) return;
            path += ")";
            dfs(left + 1, right);
            path.pop_back();
            path += "(";
            dfs(left, right + 1);
            path.pop_back();
        };
        dfs(0, 0);
        return ret;
    }
};
