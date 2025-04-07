#include<vector>
using namespace std;
#include<iostream>
#include<numeric>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        cout << count << endl;
        for (int start = 0; start < count; ++start) {
            int current = start;
            int pre = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], pre);
                current = next;
            } while (current != start);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution sol;
    sol.rotate(nums, 2);
    return 0;
}
