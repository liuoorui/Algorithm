class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        dfs(ans, curr, k, n, 1);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>> &ans, vector<int> &curr, 
             int k, int n, int num) {
        if (n < 0) return;
        if (k <= 0) {
            if (n == 0) ans.push_back(curr);
            return;
        }
        if (num > 9) return;
        
        dfs(ans, curr, k, n, num + 1);
        
        curr.push_back(num);
        dfs(ans, curr, k - 1, n - num, num + 1);
        curr.pop_back();
    }
};
