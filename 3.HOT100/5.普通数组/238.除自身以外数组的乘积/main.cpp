#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        ret[0] = 1;
        for (int i = 1; i < n; ++i) {
            ret[i] = ret[i - 1] * nums[ i - 1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; --i) {
            ret[i] = R * ret[i];
            R *= nums[i];
        }
        return ret;
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

int main(int argc, const char** argv) {
    vector<int> nums = {4, 5, 1, 8, 2};
    nums = {1, 2, 3, 4};
    Solution sol;
    auto ret = sol.productExceptSelf(nums);
    print1DIntVector(ret);
}