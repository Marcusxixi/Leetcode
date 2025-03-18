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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode * pre = dummy;
        while (pre->next != nullptr){
            if (pre->next->val == val){
                pre->next = pre->next->next;
            }
            else{
                pre = pre->next;
            }
        }
        return dummy->next;
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
    
    sol.printResult(head);
    return 0;
}