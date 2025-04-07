#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == candidate) ++count;
            else if (--count < 0) {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};