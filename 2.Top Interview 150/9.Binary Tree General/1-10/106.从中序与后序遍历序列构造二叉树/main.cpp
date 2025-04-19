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
    unordered_map<int, int> index;
    vector<int>* inorder;
    vector<int>* postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = &inorder;
        this->postorder = &postorder;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(0, n - 1, 0, n - 1);
    }

    TreeNode* myBuildTree(int pos_left, int pos_right, int in_left, int in_right) {
        if (pos_left > pos_right) return nullptr;

        int pos_root = pos_right;

        int in_root = index[(*postorder)[pos_right]];
        TreeNode* root = new TreeNode((*postorder)[pos_right]);

        int size_right = in_right - in_root;
        
        root->right = myBuildTree(pos_right - size_right, pos_right - 1, in_root + 1, in_right);
        root->left = myBuildTree(pos_left, pos_right - size_right - 1, in_left, in_root - 1);
        return root;
    }
};