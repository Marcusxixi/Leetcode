#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
    private:
        vector<int> arr;
        int index;
        int size;
    
    public:
    
        BSTIterator(TreeNode* root) {
            initArr(root);
            size = arr.size();
            index = 0;
    
        }
        
        int next() {
            return arr[index++];
        }
        
        bool hasNext() {
            return index < size;
        }
    
        void initArr(TreeNode* root) {
            if (!root) return;
            initArr(root->left);
            arr.emplace_back(root->val);
            initArr(root->right);
        }
    };
    
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * BSTIterator* obj = new BSTIterator(root);
     * int param_1 = obj->next();
     * bool param_2 = obj->hasNext();
     */