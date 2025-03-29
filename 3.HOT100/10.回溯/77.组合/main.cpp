#include <vector>
using namespace std;
#include<functional>

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            int d = k - path.size();
            if (i < d) return;
            if (path.size() == k) {
                ret.push_back(path);
            }

            for (int j = i; j > 0; --j) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }

        };

    }
};