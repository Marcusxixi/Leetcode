#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size();
        while (left < right) {
            int mid = (right + left + 1) >> 1;
            int count = 0;
            for (int i = 0; i < citations.size(); ++i) {
                if (citations[i] >= mid) ++count;
            }
            if (count >= mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};