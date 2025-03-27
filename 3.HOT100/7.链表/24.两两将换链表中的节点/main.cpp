
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * newHead = head->next;
        // 3 指向 4 的下一位(nullptr)
        head->next = swapPairs(newHead->next);
        // 4 指向 3
        newHead->next = head;
        // 返回 4，接着去上一层
        return newHead;
    }
};