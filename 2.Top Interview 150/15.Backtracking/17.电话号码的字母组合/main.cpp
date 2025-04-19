#include<string>
#include<vector>
#include<functional>
using namespace std;
#include<iostream>

class Solution {
private:
    vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        vector<string> ret;
        string path(n, 0);

        function<void(int)> dfs = [&](int index) -> void {
            if (index == n) {
                ret.emplace_back(path);
                return;
            }
            for (const char& ch: key[digits[index] - '0']) {
                path[index] = ch;
                dfs(index + 1);
            }
        };
        dfs(0);
        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    vector<string> ret = sol.letterCombinations("2001060843");
    for (auto r: ret) {
        cout << r << endl;
    }
}