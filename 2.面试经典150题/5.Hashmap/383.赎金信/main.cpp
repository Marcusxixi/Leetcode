#include<string>
using namespace std;
#include<unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> hash_table;
        for (char& ch: magazine) {
            ++hash_table[ch];
        }

        for (char& ch: ransomNote) {
            if (!hash_table.count(ch) || --hash_table[ch] < 0) return false;
        }
        return true;
    }
};