#include<vector>
using namespace std;
#include<functional>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }

    Node* build(const vector<vector<int>>& grid, int x, int y, int length) {
        // 1.判断当前区域是否纯净的 (全部是 0 或者全部是 1)
        bool same = true;
        int val = grid[x][y];
        for (int i = x; i < x + length; ++i) {
            for (int j = y; j < y + length; ++j) {
                if (grid[i][j] != val) {
                    same = false;
                    break;
                }
            }
            if (!same) break;;
        }

        // 2.如果是纯净的，直接返回叶子节点
        if (same) return new Node(val == 1, true);

        // 3.否则被划分为四个个区域
        int half = length / 2;
        Node* topLeft = build(grid, x, y, half);
        Node* topRight = build(grid, x, y + half, half);
        Node* bottomLeft = build(grid, x + half, y, half);
        Node* bottomRight = build(grid, x + half, y + half, half);
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};