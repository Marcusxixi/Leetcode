#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size(), left = 0, right = 0;
        while (right < size){
            if (nums[right] != val) {
                swap(nums[left], nums[right]);
                left ++;
            }
            right++;
        }
        return left;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}