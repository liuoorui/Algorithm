#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPos = 1, maxNeg = 1, ans = 0x80000000;
        
        for (int num: nums) {
            int a = maxPos*num, b = maxNeg*num;
            
            ans = max(ans, max(a, b));
            
            maxPos = max(1, max(a, b));
            maxNeg = min(1, min(a, b));
        }
        
        return ans;
    }
};