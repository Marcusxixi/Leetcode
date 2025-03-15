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
        for (int left = 0, right = s.size() - 1; left < right; ++left, --right) {
            swap(s[left], s[right]);
        }
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    vector<char> s = {'a', 'b', 'c', 'd', 'e'};

    sol.reverseString(s);
    for (auto ss: s){
        cout << ss << " ";
    }
    cout << endl;
    return 0;
}