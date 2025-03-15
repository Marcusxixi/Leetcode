#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {};
        vector<int> subset = {};
        dfs(nums, result, subset, 0);
        return result;
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& sub_set, int index) {
        result.push_back(sub_set);
        for (int i = index; i < nums.size(); i++) {
            sub_set.push_back(nums[i]);
            dfs(nums, result, sub_set, i + 1);
            sub_set.pop_back();
        }
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    auto ret = sol.subsets(nums);
    for (const auto& subset : ret) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}