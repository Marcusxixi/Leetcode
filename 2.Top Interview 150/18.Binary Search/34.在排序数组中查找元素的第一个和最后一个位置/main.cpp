#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        cout << search(nums, target) << endl; 
        cout << search(nums, target + 1) << endl; 
        int start = search(nums, target);
        if(start == nums.size() || nums[start] != target) return {-1, -1};
        return {search(nums, target), search(nums, target + 1) - 1};
    }
    int search(vector<int>& nums, int target){
        // left  target  mid    right
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution sol;
    sol.searchRange(nums, 8);
    return 0;
}
