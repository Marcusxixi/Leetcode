#include<string>
#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_table;
        for (string& word: strs) {
            int count[26] = {0};
            for (char& ch: word) {
                ++count[ch - 'a'];
            }

            string key = "";
            for (int i = 0; i < 26; ++i) {
                if (count[i] != 0) {
                    key +=(i + 'a');
                    key += to_string(count[i]);
                }
            }
            hash_table[key].emplace_back(word);
        }
        vector<vector<string>> ret;
        for (auto& it: hash_table) {
            ret.emplace_back(it.second);
        }
        return ret;
    }
};