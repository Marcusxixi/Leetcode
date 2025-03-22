#include<stack>
#include<iostream>
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
    bool isPalindrome(ListNode* head) {
        if (!head->next) return 1;

        ListNode* firstHalfEnd = getFisrtHalfEnd(head);
        ListNode* secondHaldStart = reverseList(firstHalfEnd->next);

        ListNode* p1 = head;
        ListNode* p2 = secondHaldStart;

        while (p2) {
            if (p1->val != p2->val) return 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        return 1;
    }

    ListNode * getFisrtHalfEnd(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    ListNode* head = new ListNode(1);
    cout << sol.isPalindrome(head) << endl;
    delete head;
    return 0;
}
