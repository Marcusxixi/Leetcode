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

    bool isValid(TreeNode* lson, TreeNode* rson) {
        if (!lson || !rson) return lson == rson;
        return isValid(lson->left, rson->right) &&isValid(rson->left, lson->right) && lson->val == rson->val;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isValid(root->left, root->right);
    }
};