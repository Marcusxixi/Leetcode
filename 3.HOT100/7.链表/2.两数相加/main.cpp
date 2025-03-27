
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
        ListNode* head = nullptr, *tail = nullptr;
        int carry = 0;
        while(l1 || l2 || carry) {
            if (l1) carry += l1->val;
            if (l2) carry += l2->val;

            if (!head) head = tail = new ListNode(carry % 10);
            else {
                tail->next = new ListNode(carry % 10);
                tail = tail->next;
            }
            carry = carry / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head;
    }
};