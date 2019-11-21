class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int cnt = 0;
        solve(root, sum, cnt);
        
        return cnt + pathSum(root->left, sum) + 
               pathSum(root->right, sum);
    }
    
private:
    void solve(const TreeNode* root, int sum, int& cnt) {
        if (!root) return;
        sum -= root->val;
        
        if (sum == 0) ++cnt;
        solve(root->left, sum, cnt);
        solve(root->right, sum, cnt);
    }
};
