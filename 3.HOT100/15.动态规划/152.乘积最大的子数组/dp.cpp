#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long ret = nums[0], max_p = nums[0], min_p = nums[0];
        
        for (int i = 1; i < n; ++i) {
            int ap = max_p, ip = min_p;
            max_p = max({ap * nums[i], ip * nums[i], nums[i]});
            min_p = min({ap * nums[i], ip * nums[i], nums[i]});
            ret = max(max_p, ret);
        }
        return ret;
    }
};