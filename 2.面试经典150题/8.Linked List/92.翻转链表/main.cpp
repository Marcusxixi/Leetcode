struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:

    void reverseList(ListNode * head) {
        ListNode * pre = nullptr;
        ListNode * curr = head;
        while (curr) {
            ListNode * next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * pre = dummy;
        for (int i = 0; i < left - 1; ++i) pre = pre->next;
        ListNode * end = pre;
        for (int i = 0; i < right - left + 1; i++) {
            end = end->next;
        }

        ListNode* start = pre->next;
        ListNode* rightPart = end->next;
        pre->next = nullptr;
        end->next = nullptr;

        reverseList(start);
        pre->next = end;
        start->next = rightPart;
        return dummy->next;
    }
};