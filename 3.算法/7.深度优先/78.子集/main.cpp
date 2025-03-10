#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int>& sub_set, int index) {
        ret.push_back(sub_set);

        for (int i = index; i < nums.size(); i++) {
            sub_set.push_back(nums[i]);
            dfs(nums, ret, sub_set, i + 1);
            sub_set.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub_set;
        dfs(nums, ret, sub_set, 0);
        return ret;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}