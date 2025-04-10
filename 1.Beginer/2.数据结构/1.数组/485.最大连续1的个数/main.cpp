#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int tmp_nums = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1) {
                tmp_nums++;
                max_count = max(max_count, tmp_nums);
            }
            else {
                tmp_nums = 0;
            }
        }
        return max(max_count, tmp_nums);
    }
};



int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    int ret = sol.findMaxConsecutiveOnes(nums);
    cout << ret << endl;

}