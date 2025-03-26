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
public:
    vector<TreeNode*>ret;
    void flatten(TreeNode* root) {
        if (!root) return;
        rec(root);
        for (int i = 1; i < ret.size(); ++i) {
            TreeNode * pre = ret[i - 1], * cur = ret[i];
            pre->left = nullptr;
            pre->right = cur;
        }
    }

    void rec(TreeNode* root) {
        if (! root) return;
        ret.push_back(root);
        rec(root->left);
        rec(root->right);
    }
};