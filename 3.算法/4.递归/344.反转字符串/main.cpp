#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        function<void(int, int)> rec = [&](int left, int right){
            if (left >= right) return;
            swap(s[left], s[right]);
            rec(left + 1, right - 1);       
        };
        rec(0, s.size() - 1);
    }
};


int main(int argc, char const *argv[]){
    vector<char> s = {'a', 'b', 'c', 'd', 'e'};
    Solution sol;
    sol.reverseString(s);
    for (auto ss : s) {
        cout << ss << " ";
    }
    cout << endl;
    return 0;
}