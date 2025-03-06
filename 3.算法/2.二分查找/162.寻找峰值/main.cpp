#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <climits> 
#include <functional>
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();

        int left = 0;
        int right = size - 1;
        if (size == 1) return 0;

        auto get = [&](int index) -> int{
            if (index < 0 || index >= nums.size()) return INT_MIN;
            return nums[index];
        };

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (get(mid) > get(mid + 1)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};



int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}