#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                ++left;
            }
        }
    }
};

void print1DIntVector(vector<int>& nums) {      
    string result = "{";
    for (int num: nums) {
        result += to_string(num) + ", ";
    }
    result = result.substr(0, result.size() - 2);
    result += "}";
    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    print1DIntVector(nums);
    return 0;
}
