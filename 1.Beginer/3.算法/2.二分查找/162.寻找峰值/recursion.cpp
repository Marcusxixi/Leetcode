#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        auto get = [&](int index) -> int {
            if(index < 0 || index >= nums.size()) return INT_MIN;
            return nums[index];
        };

        function<int(int, int)> rec = [&](int left, int right) -> int {
            if (left > right) return -1;
            int mid = left + (right - left) / 2;
            if (get(mid) > get(mid + 1) && get(mid) > get(mid - 1)) return mid;
            if (get(mid) < get(mid - 1)) return(rec(left, mid - 1));
            return rec(mid + 1, right);
        };

        return rec(0, size - 1);
    }
};



int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}