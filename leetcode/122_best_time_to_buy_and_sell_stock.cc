#include <iostream>
#include <vector>
using namespace std;

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