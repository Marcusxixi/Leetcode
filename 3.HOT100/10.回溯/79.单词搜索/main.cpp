#include<vector>
using namespace std;
#include<functional>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        function<bool(int, int, int)> dfs = [&](int i, int row, int col) -> bool{
            if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[i]) return 0;
            if (i == word.size() - 1) return 1;
            char tmp = board[row][col];
            board[row][col] = '*';
            bool found = dfs(i + 1, row + 1, col) ||
                         dfs(i + 1, row - 1, col) ||
                         dfs(i + 1, row, col + 1) ||
                         dfs(i + 1, row, col - 1);
            
            board[row][col] = tmp;
            return found;
        };

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(0, i, j)) return 1;
            }
        }
        return 0;
    }
};