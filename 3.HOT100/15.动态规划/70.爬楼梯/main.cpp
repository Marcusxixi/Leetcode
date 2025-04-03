#include<unordered_map>
using namespace std;
#include<iostream>

class Solution {
private:
    unordered_map<int, int> hash_table;
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int n0 = 1, n1 = 1;
        for (int i = 2; i <= n; ++i) {
            int cur = n0 + n1;
            n0 = n1;
            n1 = cur;
        }
        return n1;
    }
};

int main(int argc, char const *argv[])
{
    int n = 8;
    Solution sol;
    cout << sol.climbStairs(n) << endl;
    return 0;
}
