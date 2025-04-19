#include<vector>
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
    vector<TreeNode*> l;
public:
    void pre(TreeNode* root) {
        if (! root) return;
        l.push_back(root);
        pre(root->left);
        pre(root->right);
    }

    void flatten(TreeNode* root) {
        pre(root);
        for (int i = 1; i < l.size(); ++i) {
            TreeNode* pre = l[i - 1];
            pre->right = l[i];
            pre->left = nullptr;
        }

    }
};