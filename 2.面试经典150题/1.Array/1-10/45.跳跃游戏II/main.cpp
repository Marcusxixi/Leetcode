#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), far = 0, end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (far >= i) {
                far = max(far, i + nums[i]);
                if (i == end) {
                    end += far;
                    ++step;
                }
            }
        }
        return step;
    }
};