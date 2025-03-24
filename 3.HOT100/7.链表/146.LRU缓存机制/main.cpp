#include<unordered_map>
#include<iostream>
using namespace std;


struct DLinkListNode {
    int key, value;
    DLinkListNode * pre;
    DLinkListNode * next;
    DLinkListNode(): key(0), value(0), pre(nullptr), next(nullptr){}
    DLinkListNode(int _key, int _value) : key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkListNode*> cache;
    DLinkListNode* head;
    DLinkListNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new DLinkListNode();
        
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */