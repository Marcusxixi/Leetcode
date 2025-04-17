#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(!bankSet.count(endGene)) return -1;
        queue<pair<string, int>>q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);
        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [curr, steps] = q.front(); q.pop();
            if (curr == endGene) return steps;

            for (int i = 0; i < 8; ++i) {
                char original = curr[i];
                for (char g: genes) {
                    if (g == original)continue;
                    curr[i] = g;
                    if (bankSet.count(curr) && !visited.count(curr)) {
                        q.push({curr, steps + 1});
                        visited.insert(curr);
                    }
                }
                curr[i] = original;
            }
        }
        return -1;
        
    }
};