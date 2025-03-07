#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:

    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for(int i = lo; i <= hi; i++) {
            if (nums[i] == target) count++;
        }
        return count;
    }


    int rec(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        int mid = lo + (hi - lo) / 2;
        int left_major = rec(nums, lo, mid);
        int right_major = rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_major, lo, hi) > (hi - lo) / 2) {
            return left_major;
        }
        if (count_in_range(nums, right_major, lo, hi) > (hi - lo) / 2) {
            return right_major;
        }
        return -1;
    }   

    int majorityElement(vector<int>& nums) {
        return rec(nums, 0, nums.size() - 1);
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {6, 5, 5};
    cout << sol.majorityElement(nums) << endl;
    return 0;
}