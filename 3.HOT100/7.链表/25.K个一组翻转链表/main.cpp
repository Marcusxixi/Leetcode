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
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* pre = tail->next, *cur = head;
        while(pre != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;

        while(head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                if(!tail->next) return dummy->next;
                tail = tail->next;
            }

            ListNode* next = tail->next;
            pair<ListNode*, ListNode*> ret= myReverse(head, tail);
            head = ret.first;
            tail = ret.second;

            pre->next = head;
            tail->next = next;
            pre = head;
            head = tail->next;


        }
        return dummy->next;


    }
};