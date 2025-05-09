#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash_map;
        for (string& word: words) {
            ++hash_map[word];
        }

        // ????
        auto cmp = [] (const pair<string, int>& a, const pair<string, int>& b) -> bool{
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        
        for (auto& item: hash_map) {
            pq.emplace(item);
            if (pq.size() > k) pq.pop();
        }

        vector<string> ret(k);
        for (int i = k - 1; i >= 0; --i) {
            ret[i] = pq.top().first;
            pq.pop();
        }
        return ret;
    }
};