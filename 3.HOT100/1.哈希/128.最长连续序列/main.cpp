#include<vector>
#include<iostream>
#include<map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int num: nums) {
            hash_set.insert(num);
        }
        int ret = 0;
        for (int num: nums) {
            if (!hash_set.count(num - 1)) {
                int curRet = 1;
                int curNum = num;

                while(hash_set.count(curNum + 1)){
                    ++curNum;
                    ++curRet;
                }
                ret = max(ret, curRet);
            }
        }
        return ret;
    }
};


void printIntVector(vector<int>& nums) {      
    string result = "{";
    for (int num: nums) {
        result += to_string(num) + ", ";
    }
    result = result.substr(0, result.size() - 2);
    result += "}";
    cout << result << endl;
}

int main(int argc, const char** argv) {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution sol;
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}