#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 递增栈
        stack<int> s;
        int max_aera = 0, i = 0;
        heights.push_back(0);
        
        while (i < heights.size()) {
            if (s.empty() || heights[s.top()]<=heights[i]) {
                s.push(i++);
            } else {
                int idx = s.top(), curr_aera;
                s.pop();
                
                curr_aera = heights[idx] * (s.empty()? i: i - s.top() - 1);
                max_aera = max(max_aera, curr_aera);
            }
        }
        
        return max_aera;
    }
};