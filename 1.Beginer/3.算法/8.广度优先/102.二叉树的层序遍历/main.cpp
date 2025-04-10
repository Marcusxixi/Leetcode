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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int currentLevelSize = q.size();
            result.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode * node = q.front(); q.pop();
                result.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }            
        }
        return result;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}