#include<vector>
using namespace std;
#include<queue>

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
    vector<int> counts;
    vector<double> sums;

public:
    void dfs(TreeNode* root, int level) {
        if (!root) return;
        if (level < sums.size()) {
            sums[level] += root->val;
            ++counts[level];
        } else {
            sums.push_back(1.0 * root->val);
            counts.push_back(1);
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        this->counts = vector<int>();
        this->sums = vector<double>();
        dfs(root, 0);
        int size = counts.size();
        for (int i = 0; i < size; ++i) {
            sums[i] /= counts[i];
        }
        return sums;
    }
};