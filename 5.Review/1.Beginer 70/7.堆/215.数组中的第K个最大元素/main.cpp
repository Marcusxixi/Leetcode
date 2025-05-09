#include<vector>
using namespace std;

class Solution {
public:

    void heapify(int size, vector<int>& nums, int cur) {
        int left = cur * 2 + 1, right = left + 1;
        int largest = cur;
        if (left < size && nums[left] > nums[largest]) largest = left;
        if (right < size && nums[right] > nums[largest]) largest = right;
        if (largest != cur) {
            swap(nums[largest], nums[cur]);
            heapify(size, nums, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size(), start = size / 2 - 1;
        for (int i = start; i >= 0; --i) {
            heapify(size, nums, i);
        }

        for (int i = size - 1; i >= size - k; --i) {
            swap(nums[i], nums[0]);
            heapify(i, nums, 0);
        }
        return nums[size - k];
    }
};