#include<climits>
#include<algorithm>
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
        int ret = INT_MIN;
        int rec(TreeNode* root) {
            if (!root) return 0;
            int maxL = max(rec(root->left), 0);
            int maxR = max(rec(root->right), 0);
            int cur = root->val + maxL + maxR;
            ret = max(ret, cur);
            return root->val + max(maxL, maxR);
        }
    
        int maxPathSum(TreeNode* root) {
            rec(root);
            return ret;
        }
    };