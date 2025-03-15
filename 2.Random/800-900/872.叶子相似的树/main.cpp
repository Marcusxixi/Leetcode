#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
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
    void dfs(TreeNode* root, vector<int>& leave) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) leave.push_back(root->val);
        dfs(root->left, leave);
        dfs(root->right, leave);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leave1;
        vector<int> leave2;
        dfs(root1, leave1);
        dfs(root2, leave2);
        if (leave1.size() != leave2.size()) return false;
        for (int i = 0; i < leave1.size(); i++) {
            if (leave1[i] != leave2[i]) return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[]){
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution sol;
    sol.leafSimilar(root, root);
    return 0;
}