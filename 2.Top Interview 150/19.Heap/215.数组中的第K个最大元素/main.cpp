#include<vector>
using namespace std;

class Solution {
private:
    void heapify(vector<int>& nums, int n, int cur) {
        int left = cur * 2 + 1, right = left + 1;
        int largest = cur;
        if (left < n && nums[largest] < nums[left]) largest = left;
        if (right < n && nums[largest] < nums[right]) largest = right;
        if (largest != cur) {
            swap(nums[largest], nums[cur]);
            heapify(nums, n, largest);
        }
    }

public:


    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), start = n / 2 - 1;
        for (int i = start; i >= 0; --i) {
            heapify(nums, n, i);
        }

        for (int i = n - 1; i >= n - k; --i) {
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
        return nums[n - k];

    }
};