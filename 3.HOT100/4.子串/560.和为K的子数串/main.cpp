#include <iostream>
#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash_table;
        int pre = 0, ret = 0;
        ++hash_table[0];
        for (int x: nums) {
            pre += x;
            if (hash_table.count(pre - k)) {
                ret += hash_table[pre - k];
            }
            ++hash_table[pre];
        } 
        return ret;
    }
};

void print1DIntVector(vector<int>& nums) {      
    string result = "{";
    for (int num: nums) {
        result += to_string(num) + ", ";
    }
    result = result.substr(0, result.size() - 2);
    result += "}";
    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    Solution sol;
    cout << sol.subarraySum(nums, 3) << endl;
    return 0;
}
