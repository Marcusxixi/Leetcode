#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path(2*n, 0);
        function<void(int, int)> dfs = [&](int i, int left) {
            if (i == 2 * n) {
                ret.push_back(path);
                return;
            }

            if (left < n) {
                path[i] = '(';
                dfs(i + 1, left + 1);
            }

            if (i - left < left) {
                path[i] = ')';
                dfs(i + 1, left);
            }

        };
        dfs(0, 0);
        return ret;
    }
};