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
private:
    vector<vector<int>> ret;
public:
    void rec(TreeNode* root, int level) {
        if (!root) return;
        if (ret.size() == level) ret.push_back(vector<int>{root->val});
        else ret[level].push_back(root->val);
        rec(root->left, level + 1);
        rec(root->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        rec(root, 0);
        return ret;
    }
};