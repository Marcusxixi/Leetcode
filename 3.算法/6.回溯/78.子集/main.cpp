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
            // vector<int> temp_ret;
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
    for (const auto& subset : ret) { // 遍历每个子集
        for (int num : subset) { // 遍历子集中的每个元素
            cout << num << " "; // 打印元素，用空格分隔
        }
        cout << endl; // 每行结束后换行
    }
    return 0;
}