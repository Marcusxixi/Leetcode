#include<vector>
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeRange(lists, 0, lists.size() - 1);
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];

        int mid = left + (right - left) >> 1;
        ListNode* leftNode = mergeRange(lists, left, mid);
        ListNode* rightNode = mergeRange(lists, mid + 1, right);
        return mergeTwoList(leftNode, rightNode);

    }

    ListNode* mergeTwoList(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1), *curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy->next;
    }
};