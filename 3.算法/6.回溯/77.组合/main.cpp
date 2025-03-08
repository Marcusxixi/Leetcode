#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result = {};
        vector<int> sub_set = {};
        backTracking(result, sub_set, k, 0, n);
        return result;
        
    }

private:
    void backTracking(vector<vector<int>>& result, vector<int>& sub_set, int k, int index, int n) {
        if (sub_set.size() >= k) {
            result.push_back(sub_set);
            return;
        }
        for (int i = index + 1; i <= n; i++) {
            sub_set.push_back(i);
            backTracking(result, sub_set, k, i, n);
            sub_set.pop_back();
        }
    }

};




int main(int argc, char const *argv[]){
    int n = 4;
    int k = 2;
    Solution * sol = new Solution();
    vector<vector<int>> result = sol->combine(n, k);
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}