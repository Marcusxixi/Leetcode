#include<string>
using namespace std;
#include<unordered_map>
#include<iostream>
#include<sstream>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;

        istringstream iss(s);
        string word;
        vector<string> split_s;
        int paLen = pattern.length();

        while (iss >> word) split_s.emplace_back(word);
        if (paLen != split_s.size()) return false;

        for (int i = 0; i < paLen; ++ i) {
            char x = pattern[i];
            string y = split_s[i];
            if ((p2s.count(x) && p2s[x] != y) || (s2p.count(y) && s2p[y] != x)) return false;
            p2s[x] = y;
            s2p[y] = x;
        } 

        return true;
    }
};

int main() {
Solution sol;
string pattern = "abba";
string s = "dog cat cat dog";
sol.wordPattern(pattern, s);
}