#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int ret = nums.size() + 1;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            count += nums[right];
            while (count >= target){ 
                ret = min(ret, right - left + 1);
                count -= nums[left];
                left++;
            } 
        }
        return ret <= nums.size() ? ret : 0;
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution sol;
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}