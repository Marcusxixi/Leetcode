#include<vector>
#include<functional>
#include<iostream>
using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        function<bool(vector<int>&)> search_inside = [&](vector<int>& arr) -> bool {
            int left = 0, right = arr.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) return 1;
                if (target < arr[mid]) right = mid - 1;
                else left = mid + 1;
            }
            return 0;
        };
        int l = 0, r = rows - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (search_inside(matrix[mid])) return 1;
            if (target < matrix[mid][0]) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 3}};
    cout << sol.searchMatrix(matrix, 3) << endl;
    return 0;
}
