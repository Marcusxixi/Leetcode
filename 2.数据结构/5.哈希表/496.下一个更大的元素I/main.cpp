#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums1.size(); i++) {
            idx[nums1[i]] = i;
        }

        vector<int> ret(nums1.size(), -1);
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int x = nums2[i];
            while (! st.empty() && x > st.top()) {
                st.pop();
            }

            if (! st.empty() && idx.count(x)) {
                ret[idx[x]] = st.top();
            }
            st.push(x);
        }
        return ret;

    }
};


int main(int argc, char const *argv[]){
    return 0;
}