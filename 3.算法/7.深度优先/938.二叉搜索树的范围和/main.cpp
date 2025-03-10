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


class Solution {
public:
    int dfs(TreeNode* root, int low, int high, int sum) {
        if (root == nullptr) {
            return sum;
        }

        if (root->val < high) {
            return dfs(root->left, low, high, sum + root->left->val);
        }
        if (root->val > low) {
            return dfs(root->right, low, high, sum + root->right->val);
        }
        return 0;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high, 0);
    }
};


int main(int argc, char const *argv[]){
    return 0;
}