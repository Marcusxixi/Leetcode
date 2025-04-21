#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;

        for (size_t i = 0; i < max(a.size(), b.size()); ++i) {
            carry += i < a.size() ? a.at(i) == '1' : 0;
            carry += i < b.size() ? b.at(i) == '1' : 0;
            ret.push_back(carry % 2 == 1 ? '1' : '0');
            carry /= 2;
        }
        if (carry) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};