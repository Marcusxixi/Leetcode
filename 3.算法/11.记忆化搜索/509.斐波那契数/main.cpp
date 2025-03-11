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

    int helper(int n, unordered_map<int, int>& cache) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (cache.count(n)) return cache[n];

        int result = helper(n - 1, cache) + helper(n - 2, cache);
        cache[n] = result;
        return result;
    }

    int fib(int n) {
        unordered_map<int, int> cache;
        return helper(n, cache);
    }
};


int main(int argc, char const *argv[]){
    return 0;
}