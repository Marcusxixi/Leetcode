#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num : nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) ret |= (1 << i);
        }
        return ret;
    }
};  