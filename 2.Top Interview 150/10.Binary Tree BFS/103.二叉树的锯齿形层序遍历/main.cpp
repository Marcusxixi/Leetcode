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
private:
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front(); q.pop();
                ret.back().emplace_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (level % 2 == 0) reverse(ret.back().begin(), ret.back().end());
            ++level;
        }
        return ret;  
    }
};