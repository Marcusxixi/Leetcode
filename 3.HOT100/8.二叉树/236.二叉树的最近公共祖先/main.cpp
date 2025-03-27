
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};




class Solution {
public:
    TreeNode * ant;
    bool dfs(TreeNode* root, TreeNode*p, TreeNode* q) {
        if (!root) return 0;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->left, p, q);

        //记录公共祖先
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ant = root;
        }
        //子树是否包含 p 或 q
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
};