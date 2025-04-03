#include<vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 记录每个字符串最后出现的位置
        int last[26];
        int length = s.size();
        // 边路字符串，记录最后出现的位置
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        // 维护当前片段的左右边界
        int start = 0, end = 0;
        for (int i = 0; i < length; ++i) {
            // 更新当前区间的右边界
            end = max(end, last[s[i]] - 'a');
            //如果当index i 已经达到区间的最右端，说明可以分割
            if (i == end) {
                partition.push_back(end - start + 1); // 记录片段长度
                start = end + 1; // 更新下一个片段的起点
            }
        }
        return partition;
    }
};