#include<vector>
using namespace std;
#include<climits>
#include<functional>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        auto get = [&] (int index) -> int {
            if (index < 0 || index >= size) return INT_MIN;
            return nums[index];
        };

        function<int(int, int)> rec = [&](int left, int right) -> int {
            if (left > right) return -1;
            int mid = left + (right - left) / 2;
            if (get(mid) > get(mid + 1) && get(mid) > get(mid - 1)) return mid;
            if (get(mid) > get(mid - 1)) return(rec(mid + 1, right));
            return rec(left, mid - 1);
        };

        return rec(0, size - 1);
    }
};