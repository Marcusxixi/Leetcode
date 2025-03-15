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
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for (auto price : prices) {
            min_price = min(min_price, price);
            max_profit = max(price - min_price, max_profit);
        }
        return max_profit;
    }
};


int main(int argc, char const *argv[]){
    return 0;
}