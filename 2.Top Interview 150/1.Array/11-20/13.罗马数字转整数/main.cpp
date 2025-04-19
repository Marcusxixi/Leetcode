#include<iostream>
using namespace std;
#include<unordered_map>

class Solution {

private:
    unordered_map<char, int> hash_table = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ret = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = hash_table[s[i]];
            if (i < n - 1 && value < hash_table[s[i + 1]]) ret -= value;
            else ret += value;
        }  
        return ret;
    }
};