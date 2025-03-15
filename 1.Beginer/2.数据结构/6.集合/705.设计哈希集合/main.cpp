#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
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
        hash_table[index].push_back(key);
    }
    
    void remove(int key) {
        if (! contains(key)) return;
        int index = hash(key);
        auto& bucket_list = hash_table[index];
        bucket_list.erase(std::remove(bucket_list.begin(), bucket_list.end(), key), bucket_list.end());

    }
    
    bool contains(int key) {
        int index = hash(key);
        const auto& bucket_list = hash_table[index];
        return std::find(bucket_list.begin(), bucket_list.end(), key) != bucket_list.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main(int argc, char const *argv[]){
    return 0;
}