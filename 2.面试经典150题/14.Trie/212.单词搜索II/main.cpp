#include<vector>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;

struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> childeren;

    TrieNode() {
        word = "";
    }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (const char& ch: word) {
        if (!node->childeren.count(ch)) node->childeren[ch] = new TrieNode();
        node = node->childeren[ch];
    }
    node->word = word;
}

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& ret) {
        char ch = board[x][y];
        if (!root->childeren.count(ch)) return;
        root = root->childeren[ch];
        // 如果这个位置的 word 不为空的话 证明已经找到了一个 word 然后将这个 word 添加到结果里面
        if (root->word.size() > 0) ret.insert(root->word);
        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[0][i];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root, ret);
                }
            }
        }
        board[x][y] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> ret;
        vector<string> ans;

        for(auto& word: words) {
            insertTrie(root, word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, ret);
            }
        }
        for (auto& word: ret) {
            ans.emplace_back(word);
        }
        return ans;

    }
};