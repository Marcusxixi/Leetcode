#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch : t) {
            ret += ch - 'a';
        }
        for (char ch : s){
            ret -= ch -'a';
        }
        return ret + 'a';
    }
};


int main(int argc, char const *argv[]){
    string s = "abcd";
    string t = "abcde";
    Solution sol;
    cout << sol.findTheDifference(s, t) << endl;
}