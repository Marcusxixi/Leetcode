#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
    public:
        int minMutation(string start, string end, vector<string>& bank) {
            unordered_set<string> bankSet(bank.begin(), bank.end());
            if (!bankSet.count(end)) return -1;
    
            queue<pair<string, int>> q;
            q.push({start, 0});
            unordered_set<string> visited;
            visited.insert(start);
    
            vector<char> genes = {'A', 'C', 'G', 'T'};
    
            while (!q.empty()) {
                auto [current, step] = q.front(); q.pop();
                if (current == end) return step;
    
                for (int i = 0; i < 8; ++i) {
                    char original = current[i];
                    for (char g : genes) {
                        if (g == original) continue;
                        current[i] = g;
                        if (bankSet.count(current) && !visited.count(current)) {
                            q.push({current, step + 1});
                            visited.insert(current);
                        }
                    }
                    current[i] = original; // 复原原来的字符
                }
            }
    
            return -1;
        }
    };
    