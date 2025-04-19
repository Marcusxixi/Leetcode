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
            function<Node*(int, int, int, int)> dfs = [&] (int rowStart, int colStart, int rowEnd, int colEnd) -> Node* {
                for (int i = rowStart; i < rowEnd; ++i) {
                    for (int j = colStart; j < colEnd; ++j) {
                        // 不是叶子节点
                        if (grid[i][j] != grid[rowStart][colStart]) {
                            int rowMid = (rowEnd + rowStart) / 2;
                            int colMid = (colEnd + colStart) / 2;
                            return new Node(true, false, 
                                dfs(rowStart, colStart, rowMid, colMid),
                                dfs(rowStart, colMid, rowMid, colEnd),
                                dfs(rowMid, colStart, rowEnd, colMid),
                                dfs(rowMid, colMid, rowEnd, colEnd)
                            );
                        }
                    }
                }
                // 返回叶子节点
                return new Node(grid[rowStart][colStart], true);
            };
            return dfs(0, 0, grid.size(), grid.size());
        }
    };