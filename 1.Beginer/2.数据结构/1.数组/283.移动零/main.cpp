#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = 0;
        while (right < size){
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    for (int num : nums) cout << num << " ";
    cout << endl;
    return 0;
}
