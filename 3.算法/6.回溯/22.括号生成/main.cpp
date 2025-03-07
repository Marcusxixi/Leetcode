#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:

    void backTrack(int n, string current, vector<string>& ret, int left, int right){
        if (current.size() == n * 2) {
            ret.push_back(current);
            return;
        }
        if (left < n) {
            current += '(';
            backTrack(n, current, ret, left + 1, right);
            current.pop_back();
        }
        if (right < n){
            current += ')';
            backTrack(n, current, ret, left, right + 1);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        backTrack(n, "", ret, 0, 0);
        return ret;



    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<string> r = sol.generateParenthesis(3);
    for (auto s : r) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}