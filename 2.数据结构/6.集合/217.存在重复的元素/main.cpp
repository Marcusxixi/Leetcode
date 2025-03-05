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
        unordered_set<int>hash_set;
        for (auto num : nums) {
            if (hash_set.count(num)) return true;
            else hash_set.insert(num);
        }
        return false;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}