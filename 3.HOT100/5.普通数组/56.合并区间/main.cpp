#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); ++i) {
            //初始化当前端点的 LEFT 和 RIGHT 
            int L = intervals[i][0], R = intervals[i][1];
            // 如果现在是第一个区间，则直接加入到结果中
            // 或者结果中最后一个的右端点比现在的左端点还小就无法合并，然后将这
            // 这个端点添加为新的端点
            if (merged.size() == 0 || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
            //否则合并这两个端点，（修改右端点选择当前或者 merged 里面最大的 R）
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};