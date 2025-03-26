#include<vector>
using namespace std;
#include<unordered_map>

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
    vector<int>preorder;
    unordered_map<int, int> index;

    //总体思路 pre-order 可以确定 root 的位置
    //         in-order 可以确定left 和 right 的位置
    TreeNode* rec(int root, int left, int right) {
        if (left > right) return nullptr; //终止递归
        TreeNode* node = new TreeNode(preorder[root]); // 创建根节点
        // 找到中序遍历中的根节点的 index
        int i = index[preorder[root]];  //划分根节点，左子树，右子树
        //通过 pre来构造树的根       通过in 来构造左和右的位置     
        node->left = rec(root + 1, left, i - 1); //左子树递归
                    //右子树的根位置等于 pre根 + left 的大小 + 1
                    // left 的大小的 i - left
        node->right = rec(root + i - left + 1, i + 1, right); //右子树递归
        return node;
    }

public:
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        return rec(0, 0, inorder.size() - 1);
    }

    
};