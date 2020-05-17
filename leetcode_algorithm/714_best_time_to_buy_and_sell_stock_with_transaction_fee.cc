class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int hold = -prices[0], sold = -fee, rest = 0;
        
        for (size_t i = 1; i < prices.size(); ++i) {
            int price = prices[i];
            int pre_hold = hold;
            
            hold = max(hold, max(sold - price, rest - price));
            rest = max(sold, rest);
            sold = pre_hold + price - fee;
        }
        
        return max(sold, rest);
    }
};
