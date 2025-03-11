#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i =0; i < nums.size(); i++) {
            if (i <= far) {
                far = max(i + nums[i], far);
                if (far >= nums.size() - 1) return true;
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {0};
    Solution sol;
    cout << sol.canJump(nums) << endl;
    return 0;
}