#include<vector>
#include<queue>
#include<functional>
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
        
        function<void(TreeNode*, int)> dfs = [&] (TreeNode *root, int level) -> void {
            if (!root) return;
            if (ret.size() == level) ret.push_back(vector<int>());

            ret[level].push_back(root->val);
            dfs(root->left, level + 1);
            dfs(root->right, level + 1);
        };
        dfs(root, 0);
        return ret;
    }
};