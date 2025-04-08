#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int cnt = 0;
            for (int i = 0; i < citations.size(); ++i) {
                if (citations[i] >= mid) ++cnt;
            }
            if (cnt >= mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};