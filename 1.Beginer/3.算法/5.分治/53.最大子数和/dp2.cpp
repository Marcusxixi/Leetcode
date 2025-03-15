#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:


    void print(vector<int>& arr) {
        for (auto a : arr) {
            cout << a << " ";
        }
        cout << endl;
    }

    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > 0) nums[i] = nums[i] + nums[i - 1];
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {-1, -2};
    int ret = sol.maxSubArray(nums);
    cout << ret << endl;
    return 0;
}