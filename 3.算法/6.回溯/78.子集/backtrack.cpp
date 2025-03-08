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
        vector<vector<int>> result = {{}};
        for (int i = 1; i < nums.size(); i++) {
            vector<int> sub_set = {};
            backTracking(nums, result, i, 0, sub_set);
        }
        return result;
    }

private:
    void backTracking(vector<int>& nums, vector<vector<int>>& ret, int length, int index, vector<int>& sub_set) {
        if (sub_set.size() == length) {
            ret.push_back(sub_set);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            sub_set.push_back(nums[i]);
            backTracking(nums, ret, length, i + 1, sub_set);
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