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
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*> & lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return combine2List(merge(lists, l, mid), merge(lists, mid + 1, r));
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