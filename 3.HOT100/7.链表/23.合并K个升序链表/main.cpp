#include<vector>
using namespace std;
#include<iostream>

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
        ListNode* ret = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            ret = combine2List(ret, lists[i]);
        }
        return ret;
    }

    ListNode* combine2List(ListNode* l1, ListNode * l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode dummy, *tail = & dummy, *aPtr = l1, * bPtr = l2;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = aPtr ? aPtr : bPtr;
        return dummy.next;
    }
};