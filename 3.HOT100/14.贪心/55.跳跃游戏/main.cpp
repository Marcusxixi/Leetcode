#include<vector>
using namespace std;
#include<climits>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i <= reach) {
                reach = max(reach, i + nums[i]);
                if (reach >= nums.size() - 1) return 1; 
            } else return 0;
        }
        return 0;
    }
};