#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0;
        vector<string> ret;
        int n = nums.size();
        for (int end = 0; end < n; ++end) {
            if (end + 1 < n && nums[end] + 1 == nums[end + 1]) continue;
            if (start == end) ret.emplace_back(to_string(nums[start]));
            else ret.emplace_back(to_string(nums[start]) + "->"  + to_string(nums[end]));
            start = end + 1;
        }
        return ret;
    }
};