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
        vector<vector<int>> ret = {{}};
        for (int i = 0; i < nums.size(); i++) {
            int ret_size = ret.size();
            for (int j = 0; j < ret_size; j++) {
                vector<int> cp = ret[j];
                cp.push_back(nums[i]);
                ret.push_back(cp);
            } 
        }
        return ret;
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