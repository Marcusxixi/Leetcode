
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
    int ret;

    void rec(TreeNode* root, int& k) {
        if (!root) return;
        rec(root->left, k);
        if (--k == 0) ret = root->val;
        rec(root->right, k);
    }  

    int kthSmallest(TreeNode* root, int k) {
        rec(root, k);
        return ret;
    }
};