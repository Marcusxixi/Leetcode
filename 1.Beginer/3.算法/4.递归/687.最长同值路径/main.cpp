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
    int longestUnivaluePath(TreeNode* root) {

        int ret = 0;

        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int{
            if (root == nullptr) return 0;
            
            int max_left = dfs(root->left);
            int max_right = dfs(root->right);

            int current_left = 0;
            int current_right = 0;

            if (root->left != nullptr && root->left->val == root->val) current_left = max_left + 1;
            if (root->right != nullptr && root->right->val == root->val) current_right = max_right + 1;

            ret = max(ret, current_left + current_right);
            return max(current_left, current_right);

        };

        dfs(root);
        return ret;
        
    }
};


int main(int argc, char const *argv[]){
    return 0;
}