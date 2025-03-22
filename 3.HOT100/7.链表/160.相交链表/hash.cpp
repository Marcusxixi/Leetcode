#include<unordered_set>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash_table;
        while(headA) {
            hash_table.insert(headA);
            headA = headA->next;
        }
        while(headB) {
            if (hash_table.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};