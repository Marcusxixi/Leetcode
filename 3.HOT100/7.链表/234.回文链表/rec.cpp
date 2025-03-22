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
private:
    ListNode * frontPointer;

public:

    bool check(ListNode* cur) {
        if (cur) {
            if (!check(cur->next)) return 0;
            if (cur->val != frontPointer->val) return 0;
            frontPointer = frontPointer->next;
        }
        return 1;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return check(head);
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
