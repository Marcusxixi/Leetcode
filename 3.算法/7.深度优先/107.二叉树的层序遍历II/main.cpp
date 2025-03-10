#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
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
    void dfs(TreeNode* root, vector<vector<int>>& result, int level) {
        if (!root) return;
        if (level >= result.size()) {
            result.insert(result.begin(), vector<int>());
        }

        int insert_index = result.size() - level - 1;
        result[insert_index].push_back(root->val);
        if (root->left) dfs(root->left, result, level + 1);
        if (root->right) dfs(root->right, result, level + 1);

    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        dfs(root, result, 0);
    }
};


int main(int argc, char const *argv[]){
    return 0;
}