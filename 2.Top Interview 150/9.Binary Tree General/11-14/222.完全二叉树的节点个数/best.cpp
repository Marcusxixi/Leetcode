#include<cmath>

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        if (left_height == right_height) {
            // 左子树的高度等于右子树的高度，则左子树必定是满二叉树
            // 节点个数应该是 2 ** 高度 - 1
              // 计算左子树的高度的时候 这里 加了 1  所以递归右子树的时候不需要加 1
            return (1 << left_height) + countNodes(root->right);
        } else {
            // 左子树高度 > 右子树的高度，说明右子树必定是满二叉树
            return (1 << right_height) + countNodes(root->left);
        }
    }

    int get_height(TreeNode* root) {
        int height = 0;
        while (root) {
            ++height;
            root = root->left;
        }
        return height;
    }
};