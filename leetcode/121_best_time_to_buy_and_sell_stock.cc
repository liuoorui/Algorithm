#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, ans = 0;
        
        for (int price: prices) {
            ans = max(ans, price-min_price);
            min_price = min(min_price, price);
        }
        
        return ans;
    }
};