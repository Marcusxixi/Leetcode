#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) num = n + 1;
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            nums[num - 1] = - abs(num - 1);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 0};
    Solution sol;
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}
