#include<vector>
#include<iostream>
using namespace std;
#include<stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode * predecessor = nullptr;

        while (root) {
            if (root->left) {
                predecessor = root->left;
                while(root->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    predecessor->right = root;
                    root = root->right;
                } else {
                    ret.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};