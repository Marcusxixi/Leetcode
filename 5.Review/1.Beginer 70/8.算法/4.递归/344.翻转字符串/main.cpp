#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        function<void(int, int)> rec = [&](int left, int right) -> void {
            if (left >= right) return;
            swap(s[left], s[right]);
            rec(left + 1, right - 1);
        };
        rec(0, s.size() - 1);
    }
};