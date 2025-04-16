#include<cmath>

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int l_deep = 0;
        int r_deep = 0;
        TreeNode* node = root;
        while (root->left) {
            l_deep += 1;
            node = node->left;
        }
        node = root;
        while (root->right) {
            r_deep += 1;
            node = node->right;
        }
        if (l_deep == r_deep) {
            return pow(2, l_deep + 1) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
        
    }
};