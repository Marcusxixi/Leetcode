#include<vector>
using namespace std;

class Solution {

private:
    string get_space(int n) {
        return string(n, ' ');
    }

    // join 返回用sep 拼接[left, right) 范围内的words 组成的字符串
    // {"hello", "every", "one", "my", "name", "is", "Marcus"}
    // left = 1, right = 4 sep = "--"    ->   every--one--my
    string join(vector<string>& words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

public:

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int right = 0, n = words.size();
        while(true) {
            int left = right; //当前行的第一个单词在 words 的位置
            int sumLen = 0;
                                                                // + right - left 是加入空格的数量
            while(right < n && sumLen + words[right].length() + right - left <= maxWidth) {
                sumLen += words[right++].length();
            }
            // 当前是最后一行
            if(right == n) {
                string s = join(words, left, n, " ");
                ret.emplace_back(s + get_space(maxWidth - s.length()));
                return ret;
            }

            int numWords = right - left;
            int numSpace = maxWidth - sumLen;

            // 当前只有一个单词：将该单词左对齐，在行末填充剩余空格
            if (numWords == 1) {
                ret.emplace_back(words[left] + get_space(numSpace));
                continue;
            }

            // 当前不止一个单词
            int avgSpaces = numSpace / (numWords - 1);
            int extraSpaces = numSpace % (numWords - 1);
            string s1 = join(words, left, left + extraSpaces + 1, get_space(avgSpaces + 1)); //拼接额外加一个空格的单词
            string s2 = join(words, left + extraSpaces + 1, right, get_space(avgSpaces)); // 拼接其余单词
            ret.emplace_back(s1 + get_space(avgSpaces) + s2);
        }
    }
};