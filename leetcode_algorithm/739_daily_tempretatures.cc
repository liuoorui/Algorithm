class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        stack<int> stk;
        
        for (int i = T.size() - 1; i >= 0; --i) {
            while (!stk.empty() && T[i] >= T[stk.top()]) 
                stk.pop();
            
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        
        return ans;
    }
};
