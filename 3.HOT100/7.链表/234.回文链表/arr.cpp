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
        vector<int>arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = arr.size() - 1; i < j; ++i, --j) {
            if (arr[i] != arr[j]) return 0;
        }
        return 1;
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
