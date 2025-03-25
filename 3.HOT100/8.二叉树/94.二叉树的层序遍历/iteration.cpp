#include<vector>
#include<iostream>
using namespace std;
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:


    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> tree_stack;
        vector<int>ret;
        while(root != nullptr || ! tree_stack.empty()) {
            while(root != nullptr) {
                tree_stack.push(root);
                root = root->left;
            }
            root = tree_stack.top();
            tree_stack.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};