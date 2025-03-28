#include <climits>

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
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return 1;
        if (!isValidBST(root->left)) return 0;
        if (root->val <= pre) return 0;
        return isValidBST(root->right);
    }
};