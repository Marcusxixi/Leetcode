#include<vector>
using namespace std;
#include<functional>
#include<climits>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        function<int(int, int)> dfs =[&](int i, int c) -> int {
            if (i < 0) {
                return c == 0 ? 0 : INT_MAX;
            }
            if (c < coins[i]) return dfs(i - 1, c);

            int notTake = dfs(i - 1, c);
            int take = dfs(i, c - coins[i]);
            if (take != INT_MAX) take += 1;

            return min(notTake, take);
        };

        int ret = dfs(n - 1, amount);
        return ret == INT_MAX ? -1 : ret;
    }
};
    