struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(-1), *tail = head;
        while (l1 || l2 || carry) {
            carry += l1 ? l1->val : 0;
            carry += l2 ? l2->val : 0;
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry = carry / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};