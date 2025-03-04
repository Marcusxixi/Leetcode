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
        vector<int> alpha(26, 0);
        for (char ch : s){
            alpha[ch - 'a']++;
        }
        for (char ch : t) {
            alpha[ch - 'a']--;
            if (alpha[ch - 'a'] < 0) return ch;
        }

        return ' ';
    }
};


int main(int argc, char const *argv[]){
    string s1 = "abcd";
    string s2 = "abcde";
    Solution sol;
    cout << sol.findTheDifference(s1, s2) << endl;
    return 0;
}