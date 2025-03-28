#include<vector>
using namespace std;
#include<iostream>

class Solution {

    void print1DIntVector(vector<int>& nums) {      
        string result = "{";
        for (int num: nums) {
            result += to_string(num) + ", ";
        }
        result = result.substr(0, result.size() - 2);
        result += "}";
        cout << result << endl;
    }
public:
    vector<vector<int>> ret;

    void backtrack(vector<int>& output, int first, int len) {
        if (first == len) {
            cout << "达到末尾，添加进结果";
            print1DIntVector(output);
            ret.emplace_back(output);
            return;
        }
    
        for (int i = first; i < len; ++i) {
            cout << "交换 " << "i = " << i << " 和 " << "first = " << first << " 前: ";
            for (int num : output) cout << num << " ";
            cout << endl;
    
            swap(output[i], output[first]);
    
            backtrack(output, first + 1, len);
    
            swap(output[i], output[first]);
    
            cout << "回溯 " << "i = " << i << " 和 " << "first = " << first << " 后: ";
            for (int num : output) cout << num << " ";
            cout << endl;
        }
    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0, nums.size());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int>nums = {1,2,3};
    sol.permute(nums);
    return 0;
}