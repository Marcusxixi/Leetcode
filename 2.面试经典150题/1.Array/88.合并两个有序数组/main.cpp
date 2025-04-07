#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1;
        int cur, tail = m + n -1;
        while (idx1 >= 0 || idx2 >= 0) {
            // 这里等于 -1 是因为 index 是从 0 开始的
            if (idx1 == -1) cur = nums2[idx2--];
            else if (idx2 == -1) cur = nums1[idx1--];
            else if (nums1[idx1] > nums2[idx2]) cur = nums1[idx1--];
            else cur = nums2[idx2--];
            nums1[tail--] = cur;
        }
    }
};