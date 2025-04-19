#include<unordered_map>
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
    DLinkListNode* head, *tail;
    int size, capacity;


public:
    LRUCache(int capacity) {
        head = new DLinkListNode();
        tail = new DLinkListNode();
        head->next = tail;
        tail->pre = head;
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkListNode* node = cache[key];
        moveToHead(node);
        return node->value;

    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkListNode* newNode = new DLinkListNode(key, value);
            cache[key] = newNode;
            addTohead(newNode);
            ++size;
            if (size > capacity) {
                DLinkListNode* rmNode =  removeTail();
                cache.erase(rmNode->key);
                delete rmNode;
                --size;
            }
        } else {
            DLinkListNode* cur = cache[key];
            cur->value  = value;
            moveToHead(cur);
        }
    }

    void addTohead(DLinkListNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void removeNode(DLinkListNode* node) {
        node->pre->next = node->next;
        node->next->pre= node->pre;
    }

    void moveToHead(DLinkListNode* node) {
        removeNode(node);
        addTohead(node);
    }

    DLinkListNode* removeTail() {
        DLinkListNode* node = tail->pre;
        removeNode(node);
        return node;

    }
};