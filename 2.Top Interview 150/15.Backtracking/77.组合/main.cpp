#include<vector>
#include<string>
#include<functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        function<void(int)> dfs = [&](int index) -> void {
            int d = k - path.size();
            if (index < d) return;
            if (path.size() == k) {
                ret.emplace_back(path);
                return;
            }
            for (int j = index; j > 0; --j) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };
        dfs(n);
        return ret;
    }
};
