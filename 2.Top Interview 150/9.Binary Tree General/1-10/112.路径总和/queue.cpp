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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue<TreeNode*> tree_q;
        queue<int> sum_q;
        tree_q.push(root);
        sum_q.push(root->val);
        while (!tree_q.empty()) {
            TreeNode* curr = tree_q.front(); tree_q.pop();
            int curr_sum = sum_q.front(); sum_q.pop();
            if (!curr->left && !curr->right) {
                if (curr_sum == targetSum) return true;
                continue;
            }
            if (curr->left) {
                tree_q.push(curr->left);
                sum_q.push(curr->left->val + curr_sum);
            }
            if (curr->right) {
                tree_q.push(curr->right);
                sum_q.push(curr->right->val + curr_sum);
            }
        }
        return false;
    }
};