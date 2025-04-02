#include<vector>
using namespace std;
#include<climits>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int min_price = INT_MAX;
        for (int cur_price : prices) {
            min_price = min(min_price, cur_price);
            profit = max(profit, cur_price - min_price);
        }
        return profit;
    }
};