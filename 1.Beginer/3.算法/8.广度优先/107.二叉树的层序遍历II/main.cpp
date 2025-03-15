#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            deque<vector<int>> result;
            if (!root) return {};
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int levelSize = q.size();
                result.push_front(vector<int>());
                for (int i = 0; i < levelSize; i++) {
                    result[0].push_back(q.front()->val);
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
                
            }
            return vector<vector<int>>(result.begin(), result.end());
        }
    };


int main(int argc, char const *argv[]){
    return 0;
}