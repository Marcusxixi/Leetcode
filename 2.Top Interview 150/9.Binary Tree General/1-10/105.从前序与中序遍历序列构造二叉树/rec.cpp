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
    const vector<int>* preorder;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = &preorder;
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(0, 0, n - 1);
        
    }

    TreeNode* myBuildTree(int root, int left, int right) {
        if (left > right) return nullptr;

        // i 是 root 在 inorder 的 index
        int i = index[(*preorder)[root]];
        TreeNode* newNode = new TreeNode((*preorder)[root]);

        newNode->left = myBuildTree(root + 1, left, i - 1);
        newNode->right = myBuildTree(root + (i - left) + 1, i + 1, right);
        return newNode;

    }
};