#include<string>
#include<vector>
using namespace std;
#include<queue>
#include<unordered_set>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>word_set(wordList.begin(), wordList.end());
        if (!word_set.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while(!q.empty()) {
            auto [word, step] = q.front(); q.pop();
            // 每个位置尝试替换成 a-z
            for (int i = 0; i < word.size(); ++i) {
                string tmp = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (tmp[i] == ch) continue;
                    tmp[i] = ch;

                    if (tmp == endWord) return step + 1;

                    if (word_set.count(tmp) && !visited.count(tmp)) {
                        q.push({tmp, step + 1});
                        visited.insert(tmp);
                    }
                }
            }
        }
        return 0;
    }
};