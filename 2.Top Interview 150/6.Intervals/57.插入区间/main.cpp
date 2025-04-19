#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ret;
        for (auto& inter: intervals) {
            if (inter[0] > right) {
                // 插入区间的右侧无交集
                if (!placed) {
                    ret.push_back({left, right});
                    placed = true;
                }
                ret.push_back(inter);
            }   // 在区间的左侧而且没有交集
            else if (inter[1] < left) {
                ret.push_back(inter);
            } else {
                // 与插入的区间有交集，计算他们之间的并集
                left = min(left, inter[0]);
                right = max(right, inter[1]);
            }
        }
        if (!placed) {
            ret.push_back({left, right});
        }
        return ret;
    }
};