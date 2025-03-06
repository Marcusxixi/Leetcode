#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return left++;
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {1,3,5};
    int target = 3;
    Solution sol;
    cout << sol.searchInsert(nums, target) << endl;
    return 0;
}