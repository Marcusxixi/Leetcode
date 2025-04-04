#include<vector>
using namespace std;
#include<functional>
#include<unordered_map>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        unordered_map<int, int> hash_table;
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0) return 0;
            if (hash_table.count(i)) return hash_table[i];
            int ret = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            hash_table[i] = ret;
            return ret;
        };
        return dfs(n);
    }
};