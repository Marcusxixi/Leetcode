#include<climits>
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
public:
    int ret = INT_MIN;

    int rec(TreeNode* root) {
        if (!root) return 0;
        int maxL = max(rec(root->left), 0);
        int maxR = max(rec(root->right), 0);
        //当前节点作为拐点的路径最高点，所以可以加左和右的路径
        int cur = root->val + maxL + maxR;
        ret = max(ret, cur);
        // 但是这里不行，因为他不是最高拐点，会形成 Y 子形路径
        // 所以返回最大单向贡献值
        return root->val + max(maxL, maxR);
    }

    int maxPathSum(TreeNode* root) {
        rec(root);
        return ret;
    }
};