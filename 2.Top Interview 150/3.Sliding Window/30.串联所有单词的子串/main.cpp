#include<string>
#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> ret;
            // s = "barfoothefoobarman"  words = ["foo", "bar"]
            //  sl = 18, m = 2,  n = 3
            // m 是 words 里面有几个单词  n 是每个单词的大小    sl 是 s 的长度
            int m = words.size(), n = words[0].size(), sl = s.length();
    
            // 最外层循环， 为什么最多 n 种其实位置，因为每个单词的长度是 n，我们想从 s的不同偏移位置
            // 例如 n == 3 时 位置 0 开始处理下标 0, 3, 6 位置从 1 开始，处理下标 1, 4, 7
            for (int i = 0; i < n && i + m * n <= sl; ++i) {
    
                //用来处理窗口中还差哪些单词或者多了哪些单词
                unordered_map<string, int> diff;
                // 在s中先框住最开始的 words里面大小，在哈希表中++
                // 首先框住的是 diff[foo]++ 和 diff[bar]++
        
                // 这两个for 主要是用来初始化窗口，现在只是将他们框住，但还没有开始滑
                // 把从 i 开始的 m 个单词加进去
                for (int j = 0; j < m; ++j) {
                    ++diff[s.substr(i + j * n, n)];
                }
                //将 words中的目标单词减去 如果 diff 是空的，说明当前窗口恰好是 words 的排列
                for (string & word: words) {
                    if (--diff[word] == 0) {
                        diff.erase(word);
                    }
                }
    
                // 开始滑动窗口
                // 内层循环,从i 开始滑动，每次滑动一个单词的长度 n 一直滑动到末尾
                // 窗口的固定大小是 m * n
                for (int start = i; start <= sl - m * n; start += n) {
                    // 不是第一个窗口，因为第一个窗口已经计算过了，所以当 i -- start 的时候直接到下面判断
                    if (start != i) {
                        // word 就是窗口右边的那个单词，也就是新的窗口 需要 hash_table++
                        string word = s.substr(start + (m - 1) * n, n);
                        if (++diff[word] == 0) { //判断单词的值是不是 0，如果是的话直接擦除
                            diff.erase(word);
                        }
                        // word是窗口左侧离开的单词 要--
                        word = s.substr(start - n, n);
                        if (--diff[word] == 0) {
                            diff.erase(word);
                        }
                    }
                    // 判断哈希表是否为空，如果是的话 将窗口下标放入结果
                    if (diff.empty()) ret.emplace_back(start);
                }
            }
            return ret;
        }
    };