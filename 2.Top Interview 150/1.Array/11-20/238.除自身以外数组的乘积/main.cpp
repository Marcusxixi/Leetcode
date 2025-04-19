#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void print1DIntVector(vector<int>& nums) {      
        string result = "{";
        for (int num: nums) {
            result += to_string(num) + ", ";
        }
        result = result.substr(0, result.size() - 2);
        result += "}";
        cout << result << endl;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lP(n), rP(n);
        lP[0] = 1;
        rP[n - 1] = 1;
        for (int i = 1; i < n; ++i) {
            lP[i] = nums[i - 1] * lP[i - 1];
        }
        for (int j = n - 2; j >= 0; --j) {
            rP[j] = nums[j + 1] * rP[j + 1];
        }

        for (int i = 0; i < n; ++i) {
            lP[i] *= rP[i];
        }
        return lP ;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4};
    Solution sol;
    sol.print1DIntVector(nums);
    vector<int> ret = sol.productExceptSelf(nums);
    sol.print1DIntVector(ret);
    return 0;
}
