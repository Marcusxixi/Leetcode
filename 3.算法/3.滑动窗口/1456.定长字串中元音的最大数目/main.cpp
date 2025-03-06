#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int maxVowels(string s, int k) {
        
        auto isaeiou = [](char ch) -> bool {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        int count = 0;
        for (int i = 0; i < k; i++) {
            count += isaeiou(s[i]);
        }
        int ret = count;
        for (int i = k; i < s.size(); i++) {
            count += isaeiou(s[i]) - isaeiou(s[i - k]);
            ret = max(ret, count);
        }
        return ret;
    }
};


int main(int argc, char const *argv[]){
    string s = "abciiidef";
    int k = 3;
    Solution sol;
    cout << sol.maxVowels(s, k) << endl;
    return 0;
}