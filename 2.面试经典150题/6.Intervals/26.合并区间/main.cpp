#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (auto& inter: intervals) {
            int L = inter[0], R = inter[1];
            if (ret.size() == 0 || ret.back()[1] < L) {
                ret.emplace_back(inter);
            } else {
                ret.back()[1] = max(ret.back()[1], R);
            }
        }
    }
};