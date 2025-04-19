#include<vector>
#include<queue>
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
    vector<int> ret;
    void rec(TreeNode* root, int deepth) {
        if (!root) return;
        if (deepth == ret.size()) ret.push_back(root->val);
        rec(root->right, deepth + 1);
        rec(root->left, deepth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        rec(root, 0);
        return ret;
    }
};