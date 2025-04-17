#include<vector>
using namespace std;
#include<unordered_map>

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return node;

        if (visited.count(node)) return visited[node];

        // clone 节点，!!!为了深拷贝我们不会克隆它的邻居的列表
        Node* cloneNode = new Node(node->val);
        // 存到哈希表中
        visited[node] = cloneNode;

        for (auto& neighbor: node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }

};