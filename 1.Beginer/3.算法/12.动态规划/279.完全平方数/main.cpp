#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;


class Solution {

public:

    int numSquares(int n) {
        vector<int> dp(INT_MAX, n + 1);
        dp[0] = 0;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < (int)sqrt(i) + 1; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    sol.numSquares(13);
    return 0;
}