#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        // 状态机解法
        int fstBuy = INT_MIN, fstSell = 0, 
            secBuy = INT_MIN, secSell = 0;
        
        for (int p: prices) {
            fstBuy = max(fstBuy, -p);
            fstSell = max(fstSell, fstBuy+p);
            secBuy = max(secBuy, fstSell-p);
            secSell = max(secSell, secBuy+p);
        }
        
        return secSell;
    }

    int maxProfit2(vector<int>& prices) {
        // 比较好想到的解法
        // 相当于左右两次交易的组合；
        // 即将问题化成前后两个简单问题；
        int n = prices.size();
        vector<int> leftProfit(n, 0);
        int minPrice = INT_MAX, maxLeftProfit = 0, 
            maxRightProfit = 0, ans = 0;
        
        for (int i=0; i<n; ++i) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else
                maxLeftProfit = max(maxLeftProfit, prices[i]-minPrice);
            leftProfit[i] = maxLeftProfit;
        }
        
        int maxPrice = 0;
        for (int i=n-1; i>=0; --i) {
            if (prices[i] > maxPrice)
                maxPrice = prices[i];
            else
                maxRightProfit = max(maxRightProfit, maxPrice-prices[i]);
            ans = max(ans, leftProfit[i]+maxRightProfit);
        }
        
        return ans;
    }
};
