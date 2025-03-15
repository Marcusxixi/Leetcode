#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {6,5,5};
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
    return 0;
}