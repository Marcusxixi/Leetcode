
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

    bool isVaild(TreeNode* root1, TreeNode* root2) {
        if (!root1 && ! root2) return true;
        if (!root1 || ! root2) return false;

        return root1->val == root2->val && 
            isVaild(root1->left, root2->right) && 
            isVaild(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (! root) return true;
        return isVaild(root->left, root->right);
    }
};