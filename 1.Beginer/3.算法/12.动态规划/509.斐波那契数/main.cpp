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
    
        int fib(int n) {
            if (n == 0) return 0;
            int pre = 0;
            int cur = 1;
            for (int i = 2; i < n + 1; i++) {
                int tmp = cur + pre;
                pre = cur;
                cur = tmp;
                
            }
            return cur;
        }
    };


int main(int argc, char const *argv[]){
    int n = 10;
    Solution sol;
    for (int i = 0; i < 100; i++) {
        cout << sol.fib(i) << endl;
    }
    
    return 0;
}