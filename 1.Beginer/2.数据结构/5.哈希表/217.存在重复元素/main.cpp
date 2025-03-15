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
        unordered_set<int> hash_table;
        for (auto i : nums) {
            if(hash_table.count(i)) {
                return true;
            } else{
                hash_table.insert(i);
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}