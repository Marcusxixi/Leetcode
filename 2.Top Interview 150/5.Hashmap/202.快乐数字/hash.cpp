#include<unordered_set>
using namespace std;

class Solution {
public:

    int get_next(int n ) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            sum += digit * digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        // 因为状态数是有限的 所以还是会回到某个数
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = get_next(n);
        }
        return n == 1;
    }
};