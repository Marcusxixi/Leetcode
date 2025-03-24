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
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = node->next;
            newNode->random = node->random == nullptr ? nullptr : node->random->next;
        }

        Node* newHead = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* newNode = node->next;
            node->next = node->next->next;
            newNode->next = newNode->next == nullptr ? nullptr : newNode->next->next;
        }
        return newHead;

    }
    
};