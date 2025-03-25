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
    // number of node
    int ret;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        ret = max(ret, L + R + 1);
        return max(L, R) + 1;
    }
    // number of edge (number of node + 1)
    int diameterOfBinaryTree(TreeNode* root) {
        ret = 1;
        dfs(root);
        return ret - 1;
    }   
};