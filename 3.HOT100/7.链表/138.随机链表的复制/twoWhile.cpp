#include<iostream>
using namespace std;
#include<unordered_map>

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
            Node* newNode = new Node(curr->val);
            hash_table[curr] = newNode;
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            Node * newNode = hash_table[curr];
            newNode->next = hash_table[curr->next];
            newNode->random = hash_table[curr->random];
            curr = curr->next;
        }
        return hash_table[head];
    }
};