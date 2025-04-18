#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        function<bool(int, int, int)> dfs = [&] (int index, int row, int col) -> bool{
            
            if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index]) return false;
            if (visited[row][col]) return false;
            if (index == word.size() - 1) return true;
            
            visited[row][col] = true;
            bool found = dfs(index + 1, row + 1, col) ||
                        dfs(index + 1, row - 1, col) ||
                        dfs(index + 1, row, col + 1) ||
                        dfs(index + 1, row, col - 1);
            visited[row][col] = false;
            return found;
        };

        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(0, i, j)) return true;
            }
        }
        return false;
    }
};