#include<iostream>
#include<vector>
using namespace std;
#include<queue>

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
        if (!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode * node = q.front();
                tmp.emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            ret.emplace_back(tmp);
        }
        return ret;

    }
};