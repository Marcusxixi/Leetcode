struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = new ListNode(0);
        slow->next = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;

    }
};