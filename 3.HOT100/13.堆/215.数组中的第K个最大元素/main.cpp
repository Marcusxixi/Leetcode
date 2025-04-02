#include<vector>
using namespace std;
#include<functional>

class Solution {
private:
    void heapify(vector<int>& nums, int n, int cur) {
        int left = cur * 2 + 1;
        int right = left + 1;
        int largest = cur;
        if (left < n && nums[left] > nums[largest]) largest = left;
        if (right < n && nums[right] > nums[largest]) largest = right;
        if (largest != cur) {
            swap(nums[largest], nums[cur]);
            heapify(nums, n, largest);
        }
    }

public:


    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int start = n / 2 - 1;
        // build heap
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