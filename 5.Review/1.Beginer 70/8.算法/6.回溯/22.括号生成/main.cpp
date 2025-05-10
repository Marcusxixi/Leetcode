#include<string>
#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string path(2 * n, 0);
        vector<string> ret;
        function<void(int, int)> dfs = [&] (int index, int left) -> void {
            if (index == n * 2) {
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