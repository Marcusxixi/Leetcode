#include<iostream>
using namespace std;
#include<vector>

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
    vector<int> ret;
    void print1DIntVector(vector<int>& nums) {      
        string result = "{";
        for (int num: nums) {
            result += to_string(num) + ", ";
        }
        result = result.substr(0, result.size() - 2);
        result += "}";
        cout << result << endl;
    }   

    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        kthSmallest(root->left, k);
        ret.push_back(root->val);
        kthSmallest(root->right, k);
        return 0;
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    
    root->left->left->left = new TreeNode(1);

    return root;
}

int main(int argc, char const *argv[])
{
    Solution sol;
    TreeNode * root = createTree();
    sol.kthSmallest(root, 2);
    sol.print1DIntVector(sol.ret);
    return 0;
}
