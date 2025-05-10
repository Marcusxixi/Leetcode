#include<vector>
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
private:
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            vector<int> path;
            for (int i = 0; i < q_size; ++i) {
                TreeNode *cur = q.front(); q.pop();
                path.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ret.push_back(path);
        }
        return ret;
    }
};