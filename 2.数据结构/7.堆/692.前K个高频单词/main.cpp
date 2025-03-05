#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash_table;
        for (auto & word : words){
            hash_table[word]++;
        }
        //定义小根堆
        auto cmp = [](const pair<string, int>&a, const pair<string, int> & b){
            return a.second == b.second? a.first < b.first : a.second > b.second;
        };
        priority

    }
};



int main(int argc, char const *argv[]){
    return 0;
}