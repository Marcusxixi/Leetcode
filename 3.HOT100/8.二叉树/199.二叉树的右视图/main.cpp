#include <queue>
#include<vector>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);
        while (! q.empty()) {
            int currSize = q.size();
            int currRet = 0;
            for (int i = 0; i < currSize; ++i) {
                TreeNode* node  = q.front();
                currRet = node->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ret.push_back(currRet);
        }
        return ret;
    }
};