#include<iostream>
using namespace std;

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

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ret = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            while (sz > 0) {
                TreeNode * node = Q.front(); Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                --sz; 
            }
            ++ret;
        }
        return ret;
    }
};