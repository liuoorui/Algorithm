class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 表示当天三种状态情况下收益。
        int hold = INT_MIN, sold = 0, rest = 0;
        
        for (const auto& price : prices) {
            int pre_sold = sold;
            sold = hold + price;
            hold = max(rest - price, hold);
            rest = max(rest, pre_sold);
        }
        
        return max(sold, rest);
    }
};
