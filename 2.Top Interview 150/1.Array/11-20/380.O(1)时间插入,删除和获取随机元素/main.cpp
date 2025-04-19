#include<vector>
using namespace std;
#include<unordered_map>

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> hash_table;

public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (hash_table.count(val)) return 0;
        int index = nums.size();
        nums.emplace_back(val);
        hash_table[val] = index;
        return 1;
    }
    
    bool remove(int val) {
        if (! hash_table.count(val)) return 0;
        int remove_idx = hash_table[val];
        int last_ele = nums.back();
        hash_table[last_ele] = remove_idx;
        nums[remove_idx] = last_ele;
        nums.pop_back();
        hash_table.erase(val);
        return 1;
    }
    
    int getRandom() {
        int randomIdx = rand()%nums.size();
        return nums[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */