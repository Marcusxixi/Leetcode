#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0; // 如果 endWord 不在列表里，直接无解

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // {当前单词, 当前步数}
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            // 每个位置尝试替换成 a-z
            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (temp[i] == c) continue;
                    temp[i] = c;

                    if (temp == endWord) return steps + 1;

                    if (wordSet.count(temp) && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push({temp, steps + 1});
                    }
                }
            }
        }
        return 0; // 没有路径
    }
};
