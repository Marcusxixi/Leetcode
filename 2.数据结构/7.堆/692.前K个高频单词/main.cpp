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
        for(const string& word : words) {
            hash_table[word]++;
        }

        auto cmp = [](const pair<string, int>& a, const pair<string, int> b) -> bool{
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

        for (const auto& item : hash_table) {
            pq.emplace(item);
            if (pq.size() > k) pq.pop();
        }

        vector<string>result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }
        return result;
    }
};



int main(int argc, char const *argv[]){
    return 0;
}