#include<iostream>
#include<vector>
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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        while(curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        curr = head;
        while (curr) {
            curr->val = nums[nums.size() - 1];
            nums.pop_back();
            curr = curr->next;
        }
        return head;
    }
};