#include<iostream>
using namespace std;

class Solution {
const vector<pair<int, string>> valuesSymbol = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

public:
    string intToRoman(int num) {
        string ret = "";
        for (auto&[value, ch]: valuesSymbol) {
            while (num >= value) {
                num -= value;
                ret += ch;
            }
        }
        return ret;
    }
};