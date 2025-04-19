struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next) return head;
        ListNode* last = head;
        int size = 1;
        while (last->next) {
            last = last->next;
            ++size;
        }
        k %= size;
        if (k == 0) return head;
        ListNode* tail = head;
        for (int i = 0; i < size - k - 1; ++i) {
            tail = tail->next;
        }
        ListNode* newHead = tail->next;

        tail->next = nullptr;
        last->next = head;
        return newHead;
    }
};