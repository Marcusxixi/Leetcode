#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:

    bool search_inside(vector<int>& array, int target) {
        int left = 0;
        int right = array.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] == target) return true;
            else if (target < array[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left <= right) {
            int mid_index = left + (right - left) / 2;
            vector<int>& mid_array = matrix[mid_index];
            if (!search_inside(mid_array, target)) {
                if (target < mid_array[0]) right = mid_index - 1;
                else left = mid_index + 1;
            } else {
                return true;
            }
        }
        return false;

    }
};


int main(int argc, char const *argv[]){
    return 0;
}