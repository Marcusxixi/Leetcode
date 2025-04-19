#include<iostream>
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
    int ret;
public:
    int rec(TreeNode* root, int sum) {
        if (!root) return 0;
        int newSum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            return newSum;
        }
        return rec(root->left, newSum) + rec(root->right, newSum);

    }

    int sumNumbers(TreeNode* root) {
        return rec(root, 0);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    Solution sol;
    cout << sol.sumNumbers(root) << endl;
    return 0;
}
