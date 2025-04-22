class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a0 = 1, a1 = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = a1 + a0;
            a0 = a1;
            a1 = tmp;
            
        }
        return a1;
    }
};