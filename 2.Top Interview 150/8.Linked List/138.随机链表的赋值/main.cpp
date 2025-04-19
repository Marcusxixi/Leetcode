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
        
        Node* curr = head;
        while (curr) {
            hash_table[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        Node* newHead = hash_table[head];
        while (curr) {
            Node * newNode = hash_table[curr];
            newNode->next = hash_table[curr->next];
            newNode->random = hash_table[curr->random];
            curr = curr->next;
        }
        return newHead;
    }
};