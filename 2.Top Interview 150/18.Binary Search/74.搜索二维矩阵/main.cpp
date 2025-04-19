#include<vector>
using namespace std;
#include<functional>

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        function<bool(vector<int>&)> searchInside = [&] (vector<int>& arr) -> bool {
            int left = 0, right = arr.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) return true;
                if (target < arr[mid]) right = mid - 1;
                else left = mid + 1;
            }
            return false;
        };

        int l = 0, r = rows - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (searchInside(matrix[mid])) return true;
            if (target < matrix[mid][0]) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};