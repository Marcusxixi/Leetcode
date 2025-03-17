#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_table;
        for(string str: strs) {
            int counts[26] = {0};
            for (char& c: str) {
                ++counts[c - 'a'];
            }

            string key = "";
            for (int i = 0; i < 26; ++i) {
                if (counts[i] != 0) {
                    key.push_back(i + 'a');
                    key.push_back(counts[i]);
                }
            }
            hash_table[key].emplace_back(str);
        }
        vector<vector<string>> result;
        for(auto& p: hash_table) {
            result.emplace_back(p.second);
        }
        return result;
    }
};

void print(vector<vector<string>>& strings) {      
    string result = "{";
    for (auto& words:strings) {
        result += "{";
        for (int i = 0; i < words.size(); i++) {
            result += words[i] + ", ";
        }
        result = result.substr(0, result.size() - 2);
    }
    result = result.substr(0, result.size() - 2);
    result += "}\n";
    cout << result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);
    print(result);
}