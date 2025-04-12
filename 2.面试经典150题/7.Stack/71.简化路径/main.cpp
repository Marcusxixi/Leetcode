#include<string>
#include<vector>
using namespace std;
#include<sstream>
#include<iostream>

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        istringstream ss(path);
        string s;
        while(getline(ss, s, '/')) {
            if (s.empty() || s == ".") continue;
            if (s != "..") stk.push_back(s);
            else if (!stk.empty()) stk.pop_back();
        }

        string ret;
        for (string& s: stk) {
            ret += '/';
            ret += s;
        }
        return stk.empty() ? "/" : ret;
    }
};
