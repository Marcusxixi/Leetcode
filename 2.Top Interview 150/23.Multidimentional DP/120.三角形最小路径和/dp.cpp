#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        function<int(int, int)> dfs = [&] (int i, int j) -> int {
            if (i == n) return 0;
            return min(dfs(i + 1, j), dfs(i + 1, j + 1)) + triangle[i][j];
        };
        return dfs(0, 0);
    }
};