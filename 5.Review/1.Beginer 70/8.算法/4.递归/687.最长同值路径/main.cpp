#include<functional>
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
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int{
            if (!root) return 0;
            int max_left = dfs(root->left);
            int max_right = dfs(root->right);

            int cur_left = 0;
            int cur_right = 0;
            if (root->left && root->left->val == root->val) cur_left = max_left + 1;
            if (root->right && root->right->val == root->val) cur_right = max_right + 1;
            ret = max(ret, cur_left + cur_right);
            return max(cur_left, cur_right);
        };

        dfs(root);
        return ret;
    }
};