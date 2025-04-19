#include<unordered_map>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> hash_table;

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (!hash_table.count(head)) {
            Node* newHead = new Node(head->val);
            hash_table[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random);
        }
        return hash_table[head];
        
    }
};