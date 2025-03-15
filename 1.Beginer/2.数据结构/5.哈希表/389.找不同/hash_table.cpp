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
        unordered_map<char, char> hash_s;
        for (char ch : t) {
            if (! hash_s.count(ch)) {
                hash_s[ch] = 1;
            } else{
                hash_s[ch]++;
            }
        }
        for (char ch :s){
            hash_s[ch]--;
        }
        
        for (auto it : hash_s){
            if (it.second != 0) {
                return it.first;
            }
        }
        return ' ';
    }

};


int main(int argc, char const *argv[]){
    return 0;
}