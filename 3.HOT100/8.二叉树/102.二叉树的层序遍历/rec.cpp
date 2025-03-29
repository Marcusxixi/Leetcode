#include<iostream>
#include<vector>
using namespace std;
#include<functional>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        function<void(TreeNode*, int)> dfs = [&] (TreeNode* root, int deepth) {
            if (!root) return;
            if (deepth == ret.size()) ret.push_back(vector<int>()); 
            ret[deepth].push_back(root->val);
            dfs(root->left, deepth + 1);
            dfs(root->right, deepth + 1);
        };
        dfs(root, 0);
        return ret;
    }
};
