#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = new ListNode(0, head);
        ListNode* cur = head;
        while (cur) {
            ListNode* nextNode = head->next;
            nextNode->next = cur;
            cur = cur->next;
        }
        return cur;
    }
};