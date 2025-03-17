#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> hash_table;
        vector<vector<string>>  result; 
        int index = 0;
        for (const string& str: strs) {
            int index = 0;
            for (const char& ch: str) {
                index += ch - 'a';
            }
            hash_table[index].emplace_back(str);
        }
        for (auto it = hash_table.begin(); it != hash_table.end(); ++ it) {
            result.emplace_back(it->second);
        }
        return result;
    }
};

void print(vector<vector<string>>& strings) {      
    string result = "{";
    for (auto& words:strings) {
        result += "{";
        for (int i = 0; i < words.size() - 1; i++) {
            result += words[i] + ", ";
        }
        result += words[words.size() - 1] + "}, ";
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