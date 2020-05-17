#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // 一天为三种状态下的利润。
        int hold = -prices[0], sold = 0, rest = 0;
        
        for (size_t i = 1; i < prices.size(); ++i) {
            int price = prices[i];
            int pre_hold = hold;
            
            hold = max(rest - price, max(hold, sold - price));
            rest = max(rest, sold);
            sold = pre_hold + price;
        }
        return max(sold, rest);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        
        for (int i=0; i<prices.size()-1; ++i) {
            int dist = prices[i+1] - prices[i];
            
            if (dist > 0) profit += dist;
        }
        
        return profit;
    }
};
