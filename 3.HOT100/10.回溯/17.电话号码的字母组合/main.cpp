#include<iostream>
#include<vector>
using namespace std;
#include<functional>
    

class Solution {
private:
    vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        string path(n, 0);
        vector<string> ret = {};
        function<void(int)> dfs = [&]( int i) {
            if (i == n) {
                ret.emplace_back(path);
                return;
            }
            for (char c: key[digits[i] - '0']) {
                path[i] = c;
                dfs(i + 1);
            }   
        };
        dfs(0);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
    
    
    
    