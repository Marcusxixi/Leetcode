#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;


class Trie {
private:
    struct TrieNode {
        vector<TrieNode*> children;  // 26 个字母
        int freq = 0;  // 单词出现次数
        string word = "";  // 存储完整单词

        TrieNode() : children(26, nullptr) {} // 初始化 26 个子节点为空
    };

    TrieNode* root;

    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string> & b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        }
    };

public:
    Trie() { root = new TrieNode(); }

    // 插入单词
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word;
        node->freq++; // 统计词频
    }

    // 深度优先遍历 Trie，收集高频单词

    void dfs(TrieNode* node, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> &pq, int k) {
        if (!node) return;

        if (node->freq > 0) { // 如果是有效单词
            pq.push({node->freq, node->word});
            if (pq.size() > k) pq.pop(); // 维护小顶堆大小为 k
        }

        // 递归遍历子节点（按字典序）
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                dfs(node->children[i], pq, k);
            }
        }
    }

    // 获取前 K 个高频单词
    vector<string> getTopKWords(int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq; // 最小堆
        dfs(root, pq, k);

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end()); // 逆序得到正确排序
        return result;
    }
};

// 计算前 k 个高频单词
class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        Trie trie;

        // 插入所有单词到 Trie
        for (const string &word: words) {
            trie.insert(word);
        }

        return trie.getTopKWords(k);
    }
};

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    Solution sol;

    vector<string> result = sol.topKFrequent(words, k);

    for (const string& word : result) {
        cout << word << " ";
    }
    return 0;
}
