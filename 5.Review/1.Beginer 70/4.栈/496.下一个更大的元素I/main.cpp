#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx;

        for (int i = 0; i < nums1.size(); ++i) {
            idx[nums1[i]] = i;
        }

        vector<int> ret(nums1.size(), -1);
        stack<int> monotonic_stk;

        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num2 = nums2[i];
            while (!monotonic_stk.empty() && num2 > monotonic_stk.top()) monotonic_stk.pop();

            if (!monotonic_stk.empty() && idx.count(num2)) ret[idx[num2]] = monotonic_stk.top();
            monotonic_stk.push(num2);
        }
        return ret;
    }
};  