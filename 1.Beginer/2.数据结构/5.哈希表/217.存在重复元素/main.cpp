#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int num: nums) {
            if (hash_set.count(num)) return true;
            hash_set.insert(num);
        }
        return false;
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {1,2,3,4,5, 1};
    Solution sol;
    cout << sol.containsDuplicate(nums) << endl;
    return 0;
}