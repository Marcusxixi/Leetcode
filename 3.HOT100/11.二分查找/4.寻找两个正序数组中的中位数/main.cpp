#include<vector>
using namespace std;
#include<iostream>

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ret.push_back(nums1[i++]);
            else ret.push_back(nums2[j++]);
        }
        while (i < nums1.size()) ret.push_back(nums1[i++]);
        while (j < nums2.size()) ret.push_back(nums2[j++]);

        int n = ret.size();
        if (n % 2 == 1) return ret[n / 2];
        return (ret[n / 2] + ret[n / 2 - 1]) / 2.0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
