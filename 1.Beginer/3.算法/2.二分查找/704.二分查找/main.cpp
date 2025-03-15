#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:

    int cut(int left, int right, vector<int>& nums, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        return cut(left, right, nums, target);
    };
    
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        return cut(left, right, nums, target);
    }
};


int main(int argc, char const *argv[]){
    return 0;
}