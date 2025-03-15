#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        int pre = 1;
        int cur = 1;
        for (int i = 2; i <= n; i++) {
            cur = pre + cur;
            pre = cur - pre;
        }
        return cur;
    }
};   


int main(int argc, char const *argv[]){
    return 0;
}