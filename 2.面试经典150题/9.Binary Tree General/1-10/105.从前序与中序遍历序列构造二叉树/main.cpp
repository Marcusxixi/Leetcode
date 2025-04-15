#include<vector>
using namespace std;
#include<unordered_map>

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
    unordered_map<int, int>index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
        
    }

    TreeNode* myBuildTree(vector<int>& preorder, vector<int>&inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right) return nullptr;

        // 根节点在 preprder 的 index
        int preorder_root = pre_left;
        // 根节点在 inorder 的 index
        int inorder_root = index[preorder[preorder_root]];

        // 先建立根节点
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 获取左子树中的节点数目
        int size_left_sub_tree = inorder_root - in_left;

        root->left = myBuildTree(preorder, inorder, pre_left + 1, pre_left + size_left_sub_tree, in_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, pre_left + size_left_sub_tree + 1, pre_right, inorder_root + 1, in_right);
        return root;
    }
};