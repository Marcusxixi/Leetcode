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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //同时判断他们是否都为 nullptr
        if (!p || !q) return q == p;
        if (p->val != q->val) return 0;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};