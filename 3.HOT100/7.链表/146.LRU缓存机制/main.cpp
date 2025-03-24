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
        tail = new DLinkListNode();
        head->next = tail;
        tail->pre = head;
        
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        // 如果 key 存在，先通过哈西边定位，再移到头节点
        DLinkListNode* node = cache[key];
        moveToHead(node);
        return node->value;

    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkListNode * node = new DLinkListNode(key, value);
            cache[key] = node;
            
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkListNode * removeNode = removeTail();
                cache.erase(removeNode->key);
                delete removeNode;
                --size;
            }
        } else {
            DLinkListNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkListNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;

    }

    void removeNode(DLinkListNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DLinkListNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkListNode * removeTail() {
        DLinkListNode* node = tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */