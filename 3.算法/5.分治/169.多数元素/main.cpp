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
        int majority = (nums.size()) / 2 + 1;
        for (auto num : nums) {
            hash_table[num] += 1;
            if (hash_table[num] >= majority) return num;
        }
        return -1;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << sol.majorityElement(nums) << endl;
    return 0;
}