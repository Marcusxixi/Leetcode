#include<vector>
using namespace std;

class MyHashSet {

private:
static const int bucket = 796;
vector<vector<int>> hash_table;

static int hash(int key) {
    return key % bucket;
}

public:
    MyHashSet() {
        hash_table.resize(bucket);
    }
    
    void add(int key) {
        if (contains(key)) return;
        int index = hash(key);
        hash_table[index].emplace_back(key);
    }
    
    void remove(int key) {
        if (!contains(key)) return;
        int index = hash(key);
        auto& list = hash_table[index];
        
        list.erase(std::remove(list.begin(), list.end(), key), list.end());
    }
    
    bool contains(int key) {
        int index = hash(key);
        const auto& list = hash_table[index];
        return std::find(list.begin(), list.end(), key) != list.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */