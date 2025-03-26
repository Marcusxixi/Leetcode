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
    bool rec(TreeNode* root, long long lower, long long upper) {
        if (! root) return 1;
        if (root->val <= lower || root->val >= upper) {
            return false;
        }

        return rec(root->left, lower, root->val) && 
                rec(root->right, root->val, upper);

    }

    bool isValidBST(TreeNode* root) {
        return rec(root, LONG_MIN, LONG_MAX);
    }
};