#include <iostream>
#include <vector>
#include <unordered_map>
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
        for (int i = nums2.size() -1; i >= 0; i--){
            int x = nums2[i];
            while (! st.empty() && x > st.top()){
                st.pop();
            }
            //我们只对nums1里面的结果处理，所以当x是nums1里面的元素才更新结果
            if (!st.empty() && idx.count(x)){
                ret[idx[x]] = st.top();
            }
            st.push(x);
        }
        return ret;


    }
};




int main(int argc, char const *argv[]){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    S sol;
    auto ret = sol.nextGreaterElement(nums1, nums2);
    for (auto it : ret){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}