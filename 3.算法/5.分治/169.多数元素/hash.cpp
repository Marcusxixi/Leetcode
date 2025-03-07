#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        int majority = nums.size() / 2;
        for(auto num : nums) {
            hash_table[num]++;
            if (hash_table[num] > majority) return num;
        }
        return -1;

    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {6,5,5};
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
    return 0;
}