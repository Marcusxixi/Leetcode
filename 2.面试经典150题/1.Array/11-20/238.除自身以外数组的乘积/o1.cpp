#include<vector>
using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        ret[0] = 1;
        for (int i = 1; i < n; ++i) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; --i) {
            ret[i] *= R;
            R *= nums[i];
        }
        return ret;
    }
};