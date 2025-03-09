#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result = {};
        backTrack(nums, result, 0, nums.size());
        return result;
    }
private:
    void print(vector<int> ret) {
        string re = "";
        for (int i = 0; i < ret.size(); i++) {
            re += to_string(ret[i]) + " ";
        }
        cout << re << endl;
    }

    void backTrack(vector<int>& output, vector<vector<int>>& result,int first, int size) {
        cout << first << endl;
        if (first == size) {
            cout << "IFFFFF  ";
            print(output);
            result.push_back(output);
            return;
        }

        for (int i = first; i < size; i++) {
            swap(output[first], output[i]);
            backTrack(output, result, first + 1, size);
            swap(output[first], output[i]);
        }
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> result =  sol.permute(nums);
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}