#include<vector>
using namespace std;
#include<climits>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = INT_MAX;
        int profit = INT_MIN;
        for(int cur_price: prices) {
            price = min(price, cur_price);
            profit = max(profit, cur_price - price);
        }
        return profit;
    }
};