#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    void heapify(vector<int>& nums, int size, int i) {
        int largest = i;
        int left = i * 2 + 1;
        int right = left + 1;

        if (left < size && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < size && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, size, largest);
        }

        

    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int start = size / 2 -1;
        for (int i = start; i >= 0; i--) {
            heapify(nums, size, i);
        }

        for(int i = size - 1; i >= size - k; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums[0];
    }
};


int main(int argc, char const *argv[]){
    return 0;
}