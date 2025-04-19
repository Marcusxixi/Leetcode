#include<functional>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        function<void(int)> dfs = [&](int index) -> void {
            // path.size()是当前已经选了几个数
            // (n - index + 1)是当前 index 开始最多还剩几个数能选
            // 如果当前已经选的数 + 剩下能选的数的个数也不够 k 个了就直接剪掉
            int added = path.size();
            int remain = n - index + 1;
            if (added + remain < k) return;
            if (path.size() == k) {
                ret.emplace_back(path);
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