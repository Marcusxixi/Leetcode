#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int& num: nums) {
            hash_set.emplace(num);
        }

        int ret = 0;
        for (const int& num: hash_set) {
            if (!hash_set.count(num - 1)) {
                int curNum = num;
                int curRet = 1;
                while (hash_set.count(num + 1)) {
                    ++curNum;
                    ++curRet;
                    ret = max(ret, curRet);
                }
            }
        }
        return ret;
    }
};