#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * new_head = this->reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;

    }

    void printResult(ListNode * head){
        while (head != nullptr){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    ListNode * new_head =  sol.reverseList(head);
    sol.printResult(new_head);
    return 0;
}