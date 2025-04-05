#include<vector>
using namespace std;
#include<cmath>
#include<functional>
#include<climits>


class Solution {

public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        function<int(int)> dfs = [&](int n) -> int {
            if (n == 0) return 0;
            if (memo[n] != -1) return memo[n];
            int minCount = INT_MAX;
            for (int j = 1; j * j <= n; ++j) {
                minCount = min(minCount, dfs(n - j * j) + 1);
            }
            memo[n] = minCount;
            return minCount;
        };
        return dfs(n);
    }
};