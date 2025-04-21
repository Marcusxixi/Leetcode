#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), len = m + n;
        int aStart = 0, bStart = 0, left = -1, right = -1;
        for (int i = 0; i <= len / 2; ++i) {
            left = right;
            if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) right = nums1[aStart++];
            else right = nums2[bStart++];
        }
        if (len % 2 == 1) return right;
        return (right + left) / 2.0;
    }
};