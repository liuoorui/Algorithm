#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, tank = 0, sum = 0, n = gas.size();
        
        for (int i=0; i<n; ++i) {
            int temp = gas[i] - cost[i];
            tank += temp;
            sum += temp;
            
            if (tank < 0) {
                tank = 0;
                ans = i + 1;
            }
        }
        
        return sum < 0? -1: ans;
    }
};