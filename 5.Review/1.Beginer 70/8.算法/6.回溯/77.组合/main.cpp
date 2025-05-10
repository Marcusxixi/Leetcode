#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;

        function<void(int)> dfs = [&] (int index) -> void {
            if (index == k) {
                ret.push_back(path);
                return;
            }

            for (int j = index; j <= n; ++j) {
                path.push_back(j);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(1);
        return ret;
    }
};