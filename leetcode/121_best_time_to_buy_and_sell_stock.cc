class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_price = INT_MAX;
        
        for (auto price : prices) {
            ans = max(ans, price - min_price);
            min_price = min(min_price, price);
        }
        return ans;
    }
};
