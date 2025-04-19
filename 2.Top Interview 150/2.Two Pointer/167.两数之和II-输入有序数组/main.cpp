#include<vector>
using namespace std;
#include<unordered_map>
#include<iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) return {left + 1, right + 1};
            if (numbers[left] + numbers[right] < target) ++left;
            else --right;
        }
        return {-1, -1};
    }
};


void print1DIntVector(vector<int> nums) {      
    string result = "{";
    for (int num: nums) {
        result += to_string(num) + ", ";
    }
    result = result.substr(0, result.size() - 2);
    result += "}";
    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> numbers = {5, 25, 75};
    Solution sol;
    print1DIntVector(sol.twoSum(numbers, 100));
    return 0;
}
