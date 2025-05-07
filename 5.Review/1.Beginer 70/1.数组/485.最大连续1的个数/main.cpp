#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len = 0, cur_max = 0;
        for (int num: nums) {
            if (num) {
                ++cur_max;
                max_len = max(max_len, cur_max);
            } else cur_max = 0;
        }
        return max_len;
    }
};