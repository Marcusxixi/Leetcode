#include<vector>
using namespace std;
#include<iostream>
#include<queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [] (ListNode * a, ListNode * b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto & listNode: lists) {
            while (listNode != nullptr) {
                pq.push(listNode);
                listNode = listNode->next;
            }
        }

        ListNode * newHead = nullptr;
        ListNode * tail = nullptr;

        if (!pq.empty()) {
            newHead = pq.top();
            pq.pop();
            tail = newHead;
        }

        while(!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
        }

        if (tail) tail->next = nullptr;
        return newHead;
        
    }

};