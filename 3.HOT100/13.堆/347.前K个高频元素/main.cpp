#include<vector>
using namespace std;
#include<unordered_map>
#include<queue>


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_table;
        for (int num: nums) {
            ++hash_table[num];
        }

        auto cmp = [] (pair<int, int>& a, pair<int, int>& b) -> bool{
            int num1 = a.second;
            int num2 = b.second;
            return num1 > num2;

        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto& it : hash_table) {
            if (pq.size() == k) {
                if (pq.top().second < it.second) {
                    pq.pop();
                    pq.push(it);
                }
            } else pq.push(it);
        }
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};